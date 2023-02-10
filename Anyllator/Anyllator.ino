/*  Anyllator!
    //#define AUDIO_MODE STANDARD
    //#define AUDIO_MODE STANDARD_PLUS
    #define AUDIO_MODE HIFI

  The sketch also sounds better with a faster sample rate, for less aliasing
  #define AUDIO_RATE 32768
  in mozzi_config.

                     3.9k
     pin 9  ---WWWW-----|-----output
                    499k           |
     pin 10 ---WWWW---- |
                                       |
                             4.7n  ==
                                       |
                                   ground
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_midi.h>
//#include <mozzi_fixmath.h>
#include <mozzi_rand.h>
#include <tables/cos2048_int8.h>
#include <tables/sin2048_int8.h>
#include <tables/saw2048_int8.h>
#include <tables/triangle2048_int8.h>
#include <tables/square_no_alias_2048_int8.h>

#define CONTROL_RATE 256

Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aCarrier(COS2048_DATA);
Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aModulator(COS2048_DATA);
Q8n8 randomModNote;
Q16n16 deviation;
Q16n16 carrier_freq, mod_freq;

void setup() {
  changeValues();
  startMozzi(CONTROL_RATE);
}

void changeValues() {

  byte randomCarrier = rand(0, 4);
  switch (randomCarrier) {
    case 0:
      aCarrier.setTable(SIN2048_DATA);
      break;
    case 1:
      aCarrier.setTable(COS2048_DATA);
      break;
    case 2:
      aCarrier.setTable(SAW2048_DATA);
      break;
    case 3:
      aCarrier.setTable(TRIANGLE2048_DATA);
      break;
    case 4:
      aCarrier.setTable(SQUARE_NO_ALIAS_2048_DATA);
      break;
  }

  byte randomMod = rand(0, 4);
  switch (randomMod) {
    case 0:
      aModulator.setTable(SIN2048_DATA);
      break;
    case 1:
      aModulator.setTable(COS2048_DATA);
      break;
    case 2:
      aModulator.setTable(SAW2048_DATA);
      break;
    case 3:
      aModulator.setTable(TRIANGLE2048_DATA);
      break;
    case 4:
      aModulator.setTable(SQUARE_NO_ALIAS_2048_DATA);
      break;
  }

  randomModNote = randMidiNote();

}

void updateControl() {

  carrier_freq = Q16n16_mtof(Q8n8_to_Q16n16(mozziAnalogRead(A0) >> 3));
  mod_freq = Q16n16_mtof(Q8n8_to_Q16n16(randomModNote));
  deviation = Q8n8_to_Q16n16(mozziAnalogRead(A1) >> 3);
  aModulator.setFreq_Q16n16(mod_freq);

  if (mozziAnalogRead(A2) > 512) {
    changeValues();
  }
  
}


int updateAudio() {
  Q15n16 modulation = deviation * aModulator.next() >> 8;
  return (int)aCarrier.phMod(modulation) << 6; // aCarrier is still only an 8 bit wave so shift up to 14 bits
}


void loop() {
  audioHook();
}
