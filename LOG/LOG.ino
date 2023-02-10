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
#include <Oscil.h> // oscillator template
#include <mozzi_midi.h>
//#include <tables/sin2048_int8.h> // sine table for oscillator

int8_t BUFFER [1024] = {};

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <16384, AUDIO_RATE> osc(BUFFER);

uint16_t readcounter = 0;

void setup() {
  startMozzi(); // uses the default control rate of 64, defined in mozzi_config.h
  //aSin.setFreq(440); // set the frequency
}


void updateControl() {

  osc.setFreq(mtof(mozziAnalogRead(A7) >> 3));

}


int updateAudio() {
  if (readcounter > 1023) {
    readcounter = 0;
  }
  BUFFER[readcounter] = (mozziAnalogRead(A0) >> 2) - 127;
  readcounter++;
  // this would make more sense with a higher resolution signal
  // but still benefits from using HIFI to avoid the 16kHz pwm noise
  return osc.next() << 6; // 8 bits scaled up to 14 bits
}


void loop() {
  audioHook(); // required here
}
