#include "scales.h"
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
volatile uint32_t phIncA = 0;

uint16_t noteMemory[] = {};
#define SAMPLE_RATE 44100.0
#define SAMPLES_PER_CYCLE 4096
#define SAMPLES_PER_CYCLE_FIXEDPOINT (4096 << 10)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)
#define MIDI_NOTES 128
#define ArrayElementCount(x) (sizeof(x) / sizeof(x[0]))
uint32_t nMidiPhaseIncrement[MIDI_NOTES];
int memoryPointer, counter, counterMax;
boolean gate;
byte waveform;
int16_t notes[32] = {};
int root = 36;
int scale = 0;
boolean change;
int note = 0;

void createNoteTable() {
  for (uint32_t unMidiNote = 0; unMidiNote < MIDI_NOTES; unMidiNote++) {
    float fFrequency = ((pow(2.0, (unMidiNote - 69.0) / 12.0)) * 440.0);
    nMidiPhaseIncrement[unMidiNote] = fFrequency * TICKS_PER_CYCLE;
  }
}

void fillNoteArray() {
  for (int i = 0; i <= 31; i++) {
    //notes[i] = random(0, 25);
    notes[i] = 0;
  }
}

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  createNoteTable();
  fillNoteArray();
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

  gate = false;
  counter = 0;
  waveform = 0;
}

void loop() {

  waveform = analogRead(0) >> 9;

  // change on click
  if (analogRead(8) > 2048 && !gate) {

    root = 24 + (analogRead(3) >> 8);
    
    scale = analogRead(2) >> 8;

    uint16_t trsh = random(0,4095);

    if(trsh < analogRead(1)) {
      change = true;
    } else {
      change = false;
    }

    if(change) {
      notes[counter] = random(0,25);  
    }

    note = notes[counter];

    switch(scale) {
      case 0:
        phIncA = nMidiPhaseIncrement[root + quantize(majTable, note, ArrayElementCount(majTable))];
        break;
      case 1:
        phIncA = nMidiPhaseIncrement[root + quantize(minTable, note, ArrayElementCount(minTable))];
        break;
      case 2:
        phIncA = nMidiPhaseIncrement[root + quantize(pentaTable, note, ArrayElementCount(pentaTable))];
        break;
      case 3:
        phIncA = nMidiPhaseIncrement[root + quantize(dorianTable, note, ArrayElementCount(dorianTable))];
        break;
      case 4:
        phIncA = nMidiPhaseIncrement[root + quantize(maj3rdTable, note, ArrayElementCount(maj3rdTable))];
        break;
      case 5:
        phIncA = nMidiPhaseIncrement[root + quantize(min3rdTable, note, ArrayElementCount(min3rdTable))];
        break;
      case 6:
        phIncA = nMidiPhaseIncrement[root + quantize(whTable, note, ArrayElementCount(whTable))];
        break;
      case 7:
        phIncA = nMidiPhaseIncrement[root + quantize(chromaTable, note, ArrayElementCount(chromaTable))];
        break;
      case 8:
        phIncA = nMidiPhaseIncrement[root + quantize(gypMajTable, note, ArrayElementCount(gypMajTable))];
        break;
      case 9:
        phIncA = nMidiPhaseIncrement[root + quantize(gypMinTable, note, ArrayElementCount(gypMinTable))];
        break;
      case 10:
        phIncA = nMidiPhaseIncrement[root + quantize(spanTable, note, ArrayElementCount(spanTable))];
        break;
      case 11:
        phIncA = nMidiPhaseIncrement[root + quantize(powerTable, note, ArrayElementCount(powerTable))];
        break;
      case 12:
        phIncA = nMidiPhaseIncrement[root + quantize(octaveTable, note, ArrayElementCount(octaveTable))];
        break;
      case 13:
        phIncA = nMidiPhaseIncrement[root + quantize(smpMajTable, note, ArrayElementCount(smpMajTable))];
        break;
      case 14:
        phIncA = nMidiPhaseIncrement[root + quantize(smpMinTable, note, ArrayElementCount(smpMinTable))];
        break;
      case 15:
        phIncA = nMidiPhaseIncrement[root + quantize(blackTable, note, ArrayElementCount(blackTable))];
        break;
      default:
        phIncA = nMidiPhaseIncrement[root + quantize(majTable, note, ArrayElementCount(majTable))];
        break;
    }

    counter++;
    if (counter > 32) {
      counter = 0;
    }
    gate = true;
  }

  if (analogRead(8) < 2048 && gate) {
    gate = false;
  }
}

void TC4_Handler() {

  TC_GetStatus(TC1, 1);

  phAccA += phIncA;
  if (phAccA > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    phAccA = 0;
  }

  int32_t outA = 0;
  int32_t outB = 0;
  int32_t outC = 0;

  switch (waveform) {

    case 0:
      outA = cs80_DATA[phAccA >> 10];
      outB = pls_DATA[phAccA >> 10];
      outC = sine_DATA[(phAccA >> 10) / 2];
      break;
    case 1:
      outA = csaw_DATA[phAccA >> 10];
      outB = plsin_DATA[phAccA >> 10];
      outC = sine_DATA[(phAccA >> 10) / 2];
      break;
    case 2:
      outA = glin_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = pls_DATA[(phAccA >> 10) / 2];
      break;
    case 3:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;
    case 4:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;
    case 5:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;
    case 6:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;
    case 7:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;
    default:
      outA = cs80_DATA[phAccA >> 10];
      outB = sine_DATA[phAccA >> 10];
      outC = sine_DATA[phAccA >> 10] ^ pls_DATA[(phAccA >> 10) / 2];
      break;

  }

  int32_t out = (outA + outB + outC) / 3;  
  out = out + 32767;
  out = out >> 4;
  dacc_write_conversion_data(DACC_INTERFACE, out);
}

int quantize(int array[], int key, int elements) {
  int value = abs(key - array[0]);
  int num = 0;

  for (int x = 0; x < elements; x++) {
    if (value > abs(key - array[x])) {
      value = abs(key - array[x]);      
      num = array[x];
    }
  }
  return num;
}

