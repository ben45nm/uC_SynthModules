#include "sine.h"
#include "saw.h"
#include "cs80.h"
#include "csaw.h"
#include "dfold.h"
#include "dig.h"
#include "glin.h"
#include "noise.h"
#include "pls.h"
#include "plsin.h"
#include "plstrain.h"
#include "tri.h"

uint32_t aPhaseAccumulator = 0;
uint32_t bPhaseAccumulator = 0;
uint32_t cPhaseAccumulator = 0;
volatile uint32_t aPhaseIncrement = 0;
volatile uint32_t bPhaseIncrement = 0;
volatile uint32_t cPhaseIncrement = 0;

int SAMPLE_RATE = 44100;
int SAMPLES_PER_CYCLE = 4096;
long SAMPLES_PER_CYCLE_FIXEDPOINT = 4096;
float TICKS_PER_CYCLE;
#define MIDI_NOTES 128
uint32_t nMidiPhaseIncrement[MIDI_NOTES];
int32_t ulOutput;
float timbre, color;
int mode;

void createNoteTable(float fSampleRate) {
  for(uint32_t unMidiNote = 0;unMidiNote < MIDI_NOTES;unMidiNote++) {
    float fFrequency = ((pow(2.0,(unMidiNote-69.0)/12.0)) * 440.0);
    nMidiPhaseIncrement[unMidiNote] = fFrequency*TICKS_PER_CYCLE;
  }
}

void setup() {
  
  TICKS_PER_CYCLE = (float)SAMPLES_PER_CYCLE_FIXEDPOINT / (float)SAMPLE_RATE;
  createNoteTable(SAMPLE_RATE);
  
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(ID_TC4);
  TC_Configure(/* clock */TC1,/* channel */1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK2);
  TC_SetRC(TC1, 1, 476); // sets <> 44.1 Khz interrupt rate
  TC_Start(TC1, 1); 
  TC1->TC_CHANNEL[1].TC_IER=TC_IER_CPCS;
  TC1->TC_CHANNEL[1].TC_IDR=~TC_IER_CPCS;
  NVIC_EnableIRQ(TC4_IRQn);
  analogWrite(DAC1,0);
  
}

void loop() {

  aPhaseIncrement = nMidiPhaseIncrement[analogRead(2)>>3];
  int a = analogRead(0);
  int b = analogRead(1);
  bPhaseIncrement = nMidiPhaseIncrement[a>>3];
  cPhaseIncrement = nMidiPhaseIncrement[b>>3];
  timbre = (float) a / 1023;
  color = (float) b / 1023;
  mode = analogRead(3) >> 6;
  
}

void TC4_Handler() {
  
  TC_GetStatus(TC1, 1);
  
  aPhaseAccumulator += aPhaseIncrement;
  if(aPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
   aPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }

  bPhaseAccumulator += bPhaseIncrement;
  if(bPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
   bPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }

  cPhaseAccumulator += cPhaseIncrement;
  if(cPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
   cPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }
  
  switch(mode) {
  
    case 0:
      ulOutput = mode0(); // 3 sines
      break;
    case 1:
      ulOutput = mode1(); // 3 saw
      break;
    case 2:
      ulOutput = mode2(); // 3 squares
      break;
    case 3:
      ulOutput = mode3(); // sine xor
      break;
    case 4:
      ulOutput = mode4(); // saw xor
      break;
    case 5:
      ulOutput = mode5(); // sine / saw wavefolder
      break;
    case 6:
      ulOutput = mode6(); // cs80 / csaw wavefolder
      break;
    case 7:
      ulOutput = mode7(); // dig / glin wavefolder
      break;
    case 8:
      ulOutput = mode8(); // sine pulse train
      break;
    case 9:
      ulOutput = mode9(); // sine fm
      break;
    case 10:
      ulOutput = mode10(); // plsin fm
      break;
    case 11:
      ulOutput = mode11(); // csaw fm
      break;
    case 12:
      ulOutput = mode12(); // pls hard sync
      break;
    case 13:
      ulOutput = mode13(); // pls hard sync
      break;
    case 14:
      ulOutput = mode14(); // pls hard sync
      break;
    case 15:
      ulOutput = mode15(); // pls hard sync
      break;
    default:
      ulOutput = mode0();
  
  }

  ulOutput = ulOutput + 32767;
  ulOutput = ulOutput >> 4;
 
  dacc_write_conversion_data(DACC_INTERFACE, ulOutput);
}

int32_t mode0() {

  return (sine_DATA[aPhaseAccumulator] + sine_DATA[bPhaseAccumulator] + sine_DATA[cPhaseAccumulator]) / 3; // 3 sines
  
}

int32_t mode1() {

  return (saw_DATA[aPhaseAccumulator] + saw_DATA[bPhaseAccumulator] + saw_DATA[cPhaseAccumulator]) / 3; // 3 saw
  
}

int32_t mode2() {

  return (pls_DATA[aPhaseAccumulator] + pls_DATA[bPhaseAccumulator] + pls_DATA[cPhaseAccumulator]) / 3; // 3 squares
  
}

int32_t mode3() {

  return ((sine_DATA[aPhaseAccumulator] ^ sine_DATA[bPhaseAccumulator]) + (sine_DATA[aPhaseAccumulator] ^ sine_DATA[cPhaseAccumulator])) >> 1; // sine XOR
  
}

int32_t mode4() {

  return ((saw_DATA[aPhaseAccumulator] ^ saw_DATA[bPhaseAccumulator]) + (saw_DATA[aPhaseAccumulator] ^ saw_DATA[cPhaseAccumulator])) >> 1; // saw XOR
  
}

int32_t mode5() {

  int32_t result = (sine_DATA[aPhaseAccumulator] * (1.0 - timbre)) + (saw_DATA[aPhaseAccumulator] * timbre); // sine / saw wavefolder
  result = result * (color * 3 + 1);
  result = result + 32767;
  if (result > 65536 || result <= 0) {
    result = abs(abs(result - 65536 % 262144) - 131072) - 65536;
  }
  result = result - 32767;
  return result;
  
}

int32_t mode6() {

  int32_t result = (cs80_DATA[aPhaseAccumulator] * (1.0 - timbre)) + (csaw_DATA[aPhaseAccumulator] * timbre); // cs80 / csaw wavefolder
  result = result * (color * 3 + 1);
  if (result > 32767 || result <= -32767) {
    result = abs(abs(result - 32767 % 131072) - 65536) - 32767;
  }
  return result;
  
}

int32_t mode7() {
  // dig / glin wavefolder
  int32_t result = (dig_DATA[aPhaseAccumulator] * (1.0 - timbre)) + (glin_DATA[aPhaseAccumulator] * timbre);
  result = result * (color * 3 + 1);
  if (result > 32767 || result <= -32767) {
    result = abs(abs(result - 32767 % 131072) - 65536) - 32767;
  }
  return result;
}

int32_t mode8() {
  // sine pulse train
  return (plstrain_DATA[aPhaseAccumulator] + (plstrain_DATA[bPhaseAccumulator] * color)) / 2;
}

int32_t mode9() {
  // sine fm
  int32_t carrierPA = (aPhaseAccumulator + (int) (sine_DATA[bPhaseAccumulator] * color)) % SAMPLES_PER_CYCLE;
  return sine_DATA[carrierPA];
}

int32_t mode10() {
  // plsin fm
  int32_t carrierPA = (aPhaseAccumulator + (int) (dfold_DATA[bPhaseAccumulator] * color)) % SAMPLES_PER_CYCLE;
  return plsin_DATA[carrierPA];
}

int32_t mode11() {
  // csaw fm
  int32_t carrierPA = (aPhaseAccumulator + (int) (plsin_DATA[bPhaseAccumulator] * color)) % SAMPLES_PER_CYCLE;
  return csaw_DATA[carrierPA];
}

int32_t mode12() {
  // pls / tri fm
  int32_t carrierPA = (aPhaseAccumulator + (int) (tri_DATA[bPhaseAccumulator] * color)) % SAMPLES_PER_CYCLE;
  return pls_DATA[carrierPA];
}

int32_t mode13() {
  // pls / tri fm
  int32_t carrierPA = (aPhaseAccumulator + (int) (cs80_DATA[bPhaseAccumulator] * color)) % SAMPLES_PER_CYCLE;
  return plsin_DATA[carrierPA];
}

int32_t mode14() {
  // pls hard sync
  if(aPhaseAccumulator < 100) {
    cPhaseAccumulator = 0;
    bPhaseAccumulator = 0;  
  }
  int32_t a = pls_DATA[aPhaseAccumulator];
  int32_t b = pls_DATA[bPhaseAccumulator];
  int32_t c = pls_DATA[cPhaseAccumulator];
  return (a+b+c) / 3;
}


int32_t mode15() {
  // dig hard sync
  if(aPhaseAccumulator < 100) {
    cPhaseAccumulator = 0;
    bPhaseAccumulator = 0;  
  }
  int32_t a = dig_DATA[aPhaseAccumulator];
  int32_t b = dig_DATA[bPhaseAccumulator];
  int32_t c = dig_DATA[cPhaseAccumulator];
  return (a+b+c) / 3;
}
