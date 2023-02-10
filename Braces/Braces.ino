#include "sine.h"
#include "saw.h"

uint32_t ulPhaseAccumulator = 0;
uint32_t mainPhaseAccumulator = 0;
uint32_t secondPhaseAccumulator = 0;
uint32_t thirdPhaseAccumulator = 0;
volatile uint32_t ulPhaseIncrement = 0;
float pot1 = 0;
float pot2 = 0;
byte mode = 0;
#define SAMPLE_RATE 22050.0
#define SAMPLES_PER_CYCLE 2048
#define SAMPLES_PER_CYCLE_FIXEDPOINT (SAMPLES_PER_CYCLE<<20)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)

#define MIDI_NOTES 128
uint32_t nMidiPhaseIncrement[MIDI_NOTES];

void createNoteTable(float fSampleRate)
{
  for (uint32_t unMidiNote = 0; unMidiNote < MIDI_NOTES; unMidiNote++)
  {
    float fFrequency = ((pow(2.0, (unMidiNote - 69.0) / 12.0)) * 440.0);
    nMidiPhaseIncrement[unMidiNote] = fFrequency * TICKS_PER_CYCLE;
  }
}

void setup()
{
  createNoteTable(SAMPLE_RATE);
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(ID_TC4);
  TC_Configure(/* clock */TC1,/* channel */1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK2);
  TC_SetRC(TC1, 1, 238); // sets <> 44.1 Khz interrupt rate
  TC_Start(TC1, 1);
  TC1->TC_CHANNEL[1].TC_IER = TC_IER_CPCS;
  TC1->TC_CHANNEL[1].TC_IDR = ~TC_IER_CPCS;
  NVIC_EnableIRQ(TC4_IRQn);
  analogWrite(DAC0, 0);
}

void loop()
{
  uint32_t ulInput = analogRead(0 >> 3);
  ulPhaseIncrement = nMidiPhaseIncrement[ulInput];
  mode = analogRead(1) >> 8;
  pot1 = analogRead(2) / 4095;
  pot2 = analogRead(3) / 4095;
}

void TC4_Handler()
{
  TC_GetStatus(TC1, 1);
  ulPhaseAccumulator += ulPhaseIncrement;   // 32 bit phase increment, see below
  if (ulPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    ulPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }

  secondPhaseAccumulator += ulPhaseIncrement * (pot1 * 2); // 32 bit phase increment, see below
  if (secondPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    secondPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }

  thirdPhaseAccumulator += ulPhaseIncrement * (pot2 * 2); // 32 bit phase increment, see below
  if (thirdPhaseAccumulator > SAMPLES_PER_CYCLE_FIXEDPOINT) {
    thirdPhaseAccumulator -= SAMPLES_PER_CYCLE_FIXEDPOINT;
  }

  mainPhaseAccumulator = ulPhaseAccumulator >> 20;
  uint32_t ulOutput = sine_DATA[mainPhaseAccumulator];
  dacc_write_conversion_data(DACC_INTERFACE, ulOutput);
}

uint32_t sineSawFold() {

  uint32_t output = 0;
  output = (sine_DATA[mainPhaseAccumulator] * (1.0 - pot1)) + (saw_DATA[mainPhaseAccumulator] * pot1);
  output = output * (pot2 * 4);
  if (output > 2048 || output <= 20480) {
    output = abs(abs(output - 2048 % 8192) - 4096) - 2048;
  }
  return output;

}

uint32_t sineXor() {

  uint32_t sine1 = sine_DATA[mainPhaseAccumulator];
  uint32_t sine2 = sine1 ^ sine_DATA[secondPhaseAccumulator >> 20];
  uint32_t sine3 = sine1 ^ sine_DATA[thirdPhaseAccumulator >> 20];
  return sine1 + sine2 + sine3;

}

uint32_t sawXor() {

  uint32_t saw1 = saw_DATA[mainPhaseAccumulator];
  uint32_t saw2 = saw1 ^ saw_DATA[secondPhaseAccumulator >> 20];
  uint32_t saw3 = saw1 ^ saw_DATA[thirdPhaseAccumulator >> 20];
  return saw1 + saw2 + saw3;

}
