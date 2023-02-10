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
#include <tables/sin8192_int8.h>
#include <mozzi_midi.h>

Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> aSin(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> bSin(SIN8192_DATA);
Oscil <SIN8192_NUM_CELLS, AUDIO_RATE> cSin(SIN8192_DATA);

float shape;
byte pot3;

byte chords[8][2] = {
  {4,7},
  {3,7},
  {4,9},
  {5,9},
  {7,12},
  {4,8},
  {5,12},
  {3,8}  
};

void setup() {
  startMozzi();
}


void updateControl() {

  // root note = pot1 / A7
  // add root from cv / A0
  // chord select = pot2 / A6
  // waveshaper = pot3 / A5

  int root = (mozziAnalogRead(7) >> 6) + 48;
  int addRoot = mozziAnalogRead(0) >> 6;
  int note = root + addRoot;
  int chord = mozziAnalogRead(6) >> 7;

  int a1 = mozziAnalogRead(1);

  aSin.setFreq(mtof(note));
  bSin.setFreq(mtof(note + chords[chord][0]));
  cSin.setFreq(mtof(note + chords[chord][1]));
  shape = (((mozziAnalogRead(5) - a1) / 1023.0) * 2.0) + 0.99;
}


int updateAudio() {

  int output = (aSin.next() + bSin.next() + cSin.next()) >> 2;

  output = output * shape;
  if (output > 128 || output <= -128) {
    output = abs(abs(output - 128 % 512) - 256) - 128;
  }
  return output << 6;

}


void loop() {
  audioHook();
}
