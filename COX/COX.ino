/*  Example playing a sinewave at a set frequency,
    using Mozzi sonification library.

    Demonstrates the use of Oscil to play a wavetable.

    This sketch using HIFI mode is not for Teensy 3.1.

    IMPORTANT: this sketch requires Mozzi/mozzi_config.h to be
    be changed from STANDARD mode to HIFI.
    In Mozz/mozzi_config.h, change
    #define AUDIO_MODE STANDARD
    //#define AUDIO_MODE HIFI
    to
    //#define AUDIO_MODE STANDARD
    #define AUDIO_MODE HIFI

    Circuit: Audio output on digital pin 9 and 10 (on a Uno or similar),
    Check the Mozzi core module documentation for others and more detail

                     3.9k
     pin 9  ---WWWW-----|-----output
                    499k           |
     pin 10 ---WWWW---- |
                                       |
                             4.7n  ==
                                       |
                                   ground

    Resistors are ±0.5%  Measure and choose the most precise
    from a batch of whatever you can get.  Use two 1M resistors
    in parallel if you can't find 499k.
    Alternatively using 39 ohm, 4.99k and 470nF components will
    work directly with headphones.

    Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users

    Tim Barrass 2012-13, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin4096_int8.h>
#include <tables/saw4096_int8.h>
#include <mozzi_midi.h>
#include <LowPassFilter.h>

Oscil <SIN4096_NUM_CELLS, AUDIO_RATE> aSin(SIN4096_DATA);
Oscil <SAW4096_NUM_CELLS, AUDIO_RATE> aSaw(SAW4096_DATA);
Oscil <SAW4096_NUM_CELLS, AUDIO_RATE> bSaw(SAW4096_DATA);

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

  aSin.setFreq(mtof((mozziAnalogRead(7) >> 3) + a0));
  aSaw.setFreq(mtof((mozziAnalogRead(7) >> 3) + 5 + a0));
  bSaw.setFreq(mtof((mozziAnalogRead(7) >> 3) + a0));
  lpf.setCutoffFreq(map(mozziAnalogRead(5), 0, 1023, 0, 170));
  pot2 = (((mozziAnalogRead(6) - a1) / 1023.0) * 2.0) + 0.99;
}


int updateAudio() {

  int sine = aSin.next();
  int saw = aSaw.next();
  int bsaw = bSaw.next();

  int output = ((sine ^ saw) >> 1) + ((sine ^ bsaw) >> 1);

  output = output * (pot2);
  if (output > 128 || output <= -128) {
    output = abs(abs(output - 128 % 512) - 256) - 128;
  }
  return lpf.next(output) << 6;

}


void loop() {
  audioHook();
}
