/*  
  
                     3.9k 
     pin 9  ---WWWW-----|-----output
                    499k           |
     pin 10 ---WWWW---- |
                                       |
                             4.7n  ==
                                       |
                                   ground
  
    HIFI MODE!!!
*/
 
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <LowPassFilter.h>
#include <mozzi_fixmath.h>
#include <mozzi_midi.h>

int8_t wavtable[512];
byte i;
int16_t value;
byte x, y, z, f;
LowPassFilter lpf;

Oscil <512, AUDIO_RATE> aSin(wavtable);

void setup(){
  startMozzi(); // uses the default control rate of 64, defined in mozzi_config.h
  i = 0;
  value = 0;
  aSin.setFreq(440); // set the frequency
}


void updateControl(){
  
  if(i > 511) {
    i = 0;
  }

  f = mozziAnalogRead(A4) >> 7;
  x = (mozziAnalogRead(A1) >> 2) + 1;
  y = (mozziAnalogRead(A2) >> 2) + 1;
  z = (mozziAnalogRead(A3) >> 2) + 1;

  switch(f) {
    
      case 0:
        value = (i * x) + (i * y) * z;
        break;
      case 1:
        value = (i * x) - (i * y) * z;
        break;
      case 2:
        value = (i + x) * (i + y) * z;
        break;
      case 3:
        value = (i * z) * (i * y) / x;
        break;
      case 4:
        value = (i * i) / (x * y) - z;
        break;
      case 5:
        value = (i * x - z) * (i * y + z);
        break;
      case 6:
        value = (i / x) * (i / y) * (i / z);
        break;
      case 7:
        value = (i * x) - (i * y) * z;
        break;
  }
  
  wavtable[i] = sin(value) * 127;

  Q16n16 midi_note = Q8n0_to_Q16n16(mozziAnalogRead(A0) >> 3); 
  aSin.setFreq_Q24n8(Q16n16_to_Q24n8(Q16n16_mtof(midi_note)));

  i++;
  
}


int updateAudio(){
  return lpf.next(aSin.next()<<6); // 8 bits scaled up to 14 bits
}


void loop(){
  audioHook(); // required here
}
