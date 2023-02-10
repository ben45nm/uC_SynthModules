/*  IMPORTANT: this sketch requires Mozzi/mozzi_config.h to be
    be changed from STANDARD mode to HIFI.
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin4096_int8.h>
#include <tables/saw4096_int8.h>
#include <tables/square_2048_int8.h>
#include <mozzi_midi.h>

Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> aSin(SIN4096_DATA);
Oscil <SAW4096_NUM_CELLS, AUDIO_RATE> aSaw(SAW4096_DATA);
Oscil <SQUARE_2048_NUM_CELLS, AUDIO_RATE> aSqu(SQUARE_2048_DATA);

byte mix;
boolean sync;

void setup() {
  sync = false;
  startMozzi();
}


void updateControl() {

  int baseNote = mtof(mozziAnalogRead(7) >> 3);

  aSin.setFreq(baseNote);
  aSaw.setFreq(baseNote);
  aSqu.setFreq(mtof((mozziAnalogRead(5) >> 3)));
  mix = mozziAnalogRead(6) >> 3;
}


int updateAudio() {

  int sine = aSin.next();
  int saw = aSaw.next();
  int squ = aSqu.next();

  if (squ == 127 && !sync) {
    aSin.setPhase(0);
    aSaw.setPhase(0);
    sync = true;
  }
  if (squ == -127 && sync) {
    sync = false;
  }

  int output = (sine * (127 - mix)) + (saw * mix);
  //output = output >> 7;
  //return output << 6;
  return output >> 1;

}


void loop() {
  audioHook();
}
