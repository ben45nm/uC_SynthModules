#include "progressions.h"
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

uint32_t phAccA = 0;
uint32_t phAccB = 0;
uint32_t phAccC = 0;
uint32_t phAccD = 0;
volatile uint32_t phIncA = 0;
volatile uint32_t phIncB = 0;
volatile uint32_t phIncC = 0;
volatile uint32_t phIncD = 0;
uint16_t noteMemory[] = {};
#define SAMPLE_RATE 44100.0
#define SAMPLES_PER_CYCLE 4096
#define SAMPLES_PER_CYCLE_FIXEDPOINT (4096 << 10)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)
#define MIDI_NOTES 128
uint32_t nMidiPhaseIncrement[MIDI_NOTES];
int memoryPointer, counter, counterMax;
boolean gate;
byte waveform;

void createNoteTable() {
  for (uint32_t unMidiNote = 0; unMidiNote < MIDI_NOTES; unMidiNote++) {
    float fFrequency = ((pow(2.0, (unMidiNote - 69.0) / 12.0)) * 440.0);
    nMidiPhaseIncrement[unMidiNote] = fFrequency * TICKS_PER_CYCLE;
  }
}

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  createNoteTable();
  analogReadResolution(12);
  analogWriteResolution(12);
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(ID_TC4);

  TC_Configure(/* clock */TC1,/* channel */1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK2);
  TC_SetRC(TC1, 1, 238); // sets <> 44.1 Khz interrupt rate
  TC_Start(TC1, 1);

  TC1->TC_CHANNEL[1].TC_IER = TC_IER_CPCS;
  TC1->TC_CHANNEL[1].TC_IDR = ~TC_IER_CPCS;

  NVIC_EnableIRQ(TC4_IRQn);
  analogWrite(DAC0, 0);
  analogWrite(DAC0, 1);
  memoryPointer = 0;
  gate = false;
  counter = 0;
  counterMax = 3;
  waveform = 0;
}

void loop() {

  uint32_t root = 36 + (analogRead(2) >> 7);
  byte progression = analogRead(1) >> 9;
  waveform = analogRead(0) >> 9;

  // change on click
  if (analogRead(9) > 2048 && !gate) {

    uint16_t rndNmb = random(0, 4095);
    if (rndNmb > analogRead(3)) {

      switch (progression) {
        case 0:
          counterMax = 3;
          phIncA = nMidiPhaseIncrement[root + a[counter][0]];
          phIncB = nMidiPhaseIncrement[root + a[counter][1]];
          phIncC = nMidiPhaseIncrement[root + a[counter][2]];
          phIncD = nMidiPhaseIncrement[root + a[counter][3]];
          break;
        case 1:
          counterMax = 7;
          phIncA = nMidiPhaseIncrement[root + b[counter][0]];
          phIncB = nMidiPhaseIncrement[root + b[counter][1]];
          phIncC = nMidiPhaseIncrement[root + b[counter][2]];
          phIncD = nMidiPhaseIncrement[root + b[counter][3]];
          break;
        case 2:
          counterMax = 11;
          phIncA = nMidiPhaseIncrement[root + c[counter][0]];
          phIncB = nMidiPhaseIncrement[root + c[counter][1]];
          phIncC = nMidiPhaseIncrement[root + c[counter][2]];
          phIncD = nMidiPhaseIncrement[root + c[counter][3]];
          break;
        case 3:
          counterMax = 7;
          phIncA = nMidiPhaseIncrement[root + d[counter][0]];
          phIncB = nMidiPhaseIncrement[root + d[counter][1]];
          phIncC = nMidiPhaseIncrement[root + d[counter][2]];
          phIncD = nMidiPhaseIncrement[root + d[counter][3]];
          break;
        case 4:
          counterMax = 3;
          phIncA = nMidiPhaseIncrement[root + e[counter][0]];
          phIncB = nMidiPhaseIncrement[root + e[counter][1]];
          phIncC = nMidiPhaseIncrement[root + e[counter][2]];
          phIncD = nMidiPhaseIncrement[root + e[counter][3]];
          break;
        case 5:
          counterMax = 7;
          phIncA = nMidiPhaseIncrement[root + f[counter][0]];
          phIncB = nMidiPhaseIncrement[root + f[counter][1]];
          phIncC = nMidiPhaseIncrement[root + f[counter][2]];
          phIncD = nMidiPhaseIncrement[root + f[counter][3]];
          break;
        case 6:
          counterMax = 3;
          phIncA = nMidiPhaseIncrement[root + g[counter][0]];
          phIncB = nMidiPhaseIncrement[root + g[counter][1]];
          phIncC = nMidiPhaseIncrement[root + g[counter][2]];
          phIncD = nMidiPhaseIncrement[root + g[counter][3]];
          break;
        case 7:
          counterMax = 3;
          phIncA = nMidiPhaseIncrement[root + h[counter][0]];
          phIncB = nMidiPhaseIncrement[root + h[counter][1]];
          phIncC = nMidiPhaseIncrement[root + h[counter][2]];
          phIncD = nMidiPhaseIncrement[root + h[counter][3]];
          break;
        default:
          counterMax = 3;
          phIncA = nMidiPhaseIncrement[root + h[counter][0]];
          phIncB = nMidiPhaseIncrement[root + h[counter][1]];
          phIncC = nMidiPhaseIncrement[root + h[counter][2]];
          phIncD = nMidiPhaseIncrement[root + h[counter][3]];
          break;
      }

    }
    counter++;
    if (counter > (counterMax)) {
      counter = 0;
    }
    gate = true;
  }

  if (analogRead(9) < 2048 && gate) {
    gate = false;
  }
}

void TC4_Handler() {

  TC_GetStatus(TC1, 1);

  phAccA += phIncA;
  if (phAccA > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    phAccA = 0;
  }

  phAccB += phIncB;
  if (phAccB > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    phAccB = 0;
  }

  phAccC += phIncC;
  if (phAccC > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    phAccC = 0;
  }

  phAccD += phIncD;
  if (phAccD > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    phAccD = 0;
  }

  int32_t outA;
  int32_t outB;
  int32_t outC;
  int32_t outD;

  switch (waveform) {

    case 0:
      outA = cs80_DATA[phAccA >> 10];
      outB = cs80_DATA[phAccB >> 10];
      outC = cs80_DATA[phAccC >> 10];
      outD = cs80_DATA[phAccD >> 10];
      break;
    case 1:
      outA = csaw_DATA[phAccA >> 10];
      outB = csaw_DATA[phAccB >> 10];
      outC = csaw_DATA[phAccC >> 10];
      outD = csaw_DATA[phAccD >> 10];
      break;
    case 2:
      outA = dfold_DATA[phAccA >> 10];
      outB = dfold_DATA[phAccB >> 10];
      outC = dfold_DATA[phAccC >> 10];
      outD = dfold_DATA[phAccD >> 10];
      break;
    case 3:
      outA = glin_DATA[phAccA >> 10];
      outB = glin_DATA[phAccB >> 10];
      outC = glin_DATA[phAccC >> 10];
      outD = glin_DATA[phAccD >> 10];
      break;
    case 4:
      outA = pls_DATA[phAccA >> 10];
      outB = pls_DATA[phAccB >> 10];
      outC = pls_DATA[phAccC >> 10];
      outD = pls_DATA[phAccD >> 10];
      break;
    case 5:
      outA = plsin_DATA[phAccA >> 10];
      outB = plsin_DATA[phAccB >> 10];
      outC = plsin_DATA[phAccC >> 10];
      outD = plsin_DATA[phAccD >> 10];
      break;
    case 6:
      outA = plstrain_DATA[phAccA >> 10];
      outB = plstrain_DATA[phAccB >> 10];
      outC = plstrain_DATA[phAccC >> 10];
      outD = plstrain_DATA[phAccD >> 10];
      break;
    case 7:
      outA = saw_DATA[phAccA >> 10];
      outB = saw_DATA[phAccB >> 10];
      outC = saw_DATA[phAccC >> 10];
      outD = saw_DATA[phAccD >> 10];
      break;
    default:
      outA = cs80_DATA[phAccA >> 10];
      outB = cs80_DATA[phAccB >> 10];
      outC = cs80_DATA[phAccC >> 10];
      outD = cs80_DATA[phAccD >> 10];
      break;

  }

  int32_t out = (outA + outB + outC + outD) / 5;
  int32_t outAdd = (outB + outD) /2;
  out = out + 32767;
  out = out >> 4;
  outAdd = outAdd + 32767;
  outAdd = outAdd >> 4;

  dacc_set_channel_selection(DACC_INTERFACE, 0);
  dacc_write_conversion_data(DACC_INTERFACE, out);
  dacc_set_channel_selection(DACC_INTERFACE, 1);
  dacc_write_conversion_data(DACC_INTERFACE, outAdd);
}

