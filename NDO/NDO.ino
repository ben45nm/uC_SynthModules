/*  IMPORTANT: this sketch requires Mozzi/mozzi_config.h to be
    be changed from STANDARD mode to HIFI.
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin4096_int8.h>
#include <tables/saw4096_int8.h>
//#include <tables/square_no_alias_2048_int8.h>
#include <mozzi_midi.h>
#include <LowPassFilter.h>

Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> aSin(SIN4096_DATA);
Oscil <SAW4096_NUM_CELLS, AUDIO_RATE> aSaw(SAW4096_DATA);
Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> bSaw(SIN4096_DATA);

float pot2;
byte pot3;
LowPassFilter lpf;
int a0, a1;

void setup() {
  startMozzi();
  lpf.setResonance(0);
}


void updateControl() {

  a0 = mozziAnalogRead(0) >> 3;
  a1 = mozziAnalogRead(1);

  aSin.setFreq(mtof(mozziAnalogRead(7) >> 3) + a0);
  aSaw.setFreq(mtof((mozziAnalogRead(7) >> 3) + 5 + a0));
  bSaw.setFreq(mtof((mozziAnalogRead(7) >> 3) + a0));
  lpf.setCutoffFreq(map(mozziAnalogRead(5), 0, 1023, 0, 170));
  pot2 = (((mozziAnalogRead(6) - a1) / 1023.0) * 2.0) + 0.99;
}


int updateAudio() {

  int sine = aSin.next();
  int saw = aSaw.next();
  int bsaw = bSaw.next();

  int output = ((sine & saw) >> 1) + ((sine & bsaw) >> 1);

  output = output * (pot2);
  if (output > 128 || output <= -128) {
    output = abs(abs(output - 128 % 512) - 256) - 128;
  }
  return lpf.next(output) << 6;

}


void loop() {
  audioHook();
}
