/*  Example applying an ADSR envelope to an audio signal
    with Mozzi sonification library.  This shows
    internal updates at CONTROL_RATE, using update() in updateControl(),
    with interpolation and output using next() at AUDIO_RATE in updateAudio().
    This is the "ordinary" way to use ADSR for smooth amplitude transitions while
    maintaining reasonable efficiency by updating internal states in updateControl().

    Demonstrates a simple ADSR object being controlled with
    noteOn() and noteOff() instructions.

    Tim Barrass 2013, CC by-nc-sa.
*/

#include <MozziGuts.h>
#include <ADSR.h>

#define CONTROL_RATE 64

//Oscil <8192, AUDIO_RATE> aOscil(SIN8192_DATA);;

// for triggering the envelope
//EventDelay noteDelay;

ADSR <CONTROL_RATE, AUDIO_RATE> envelope;

boolean gate;
byte attack_level = 255;
byte decay_level = 255;
float gain = 0;

void setup() {
  gate = false;
  startMozzi(CONTROL_RATE);
  envelope.setADLevels(attack_level, decay_level);
}


void updateControl() {

  uint16_t attack = mozziAnalogRead(A7) << 1;
  uint16_t release_ms = mozziAnalogRead(A6) << 1;
  gain = ((mozziAnalogRead(A5) / 1023.0) * 2.0) + 0.99;

  envelope.setTimes(attack, 1, 1, release_ms);

  if (mozziAnalogRead(A0) > 512 && !gate) {

    envelope.noteOn();
    gate = true;
  }

  envelope.update();
  if (mozziAnalogRead(A0) < 512 && gate) {
    gate = false;
  }
}


int updateAudio() {

  int output = envelope.next();

  output = output * gain;

  if (output > 128 || output <= -128) {
    output = abs(abs(output - 128 % 512) - 256) - 128;
  }

  return (int) output << 6;
}


void loop() {
  audioHook(); // required here
}


