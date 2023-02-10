#include "LowPassFilterDue.h"

int16_t buffer[44100] = {};
uint16_t writepos = 0;
float phAcc = 0;
float phAcc2 = 11025;
float phAcc3 = 22050;
float phAcc4 = 33075;
float phInc = 0;
uint8_t density = 1;
uint16_t grainsize = 0;
int32_t sigOutL = 0;
int32_t sigOutR = 0;
uint16_t feedback = 0;
int16_t buffered = 0;
LowPassFilterDue lpf;
LowPassFilterDue lpf2;
int cutoff;


void setup() {
  //Serial.begin(9600);
  analogReadResolution(12);
  analogWriteResolution(12);
}

void loop() {

  //Serial.println(analogRead(A0));

  // mix input and buffered sample
  long in = analogRead(A0) - 2047;

in = in + buffered;

  in = in * ((analogRead(A4) >> 9)+1);

  

  // fold signal to prevent clipping
  if (in > 2047 || in <= -2047) {
    in = abs(abs(in - 2047 % 8191) - 4095) - 2047;
  }

  // write to buffer
  buffer[writepos] = in;
  writepos++;
  //boolean freeze = digitalRead(22);

  //if(!freeze) {
    if (writepos > 44100) {
      writepos = 0;
    }
  //}

  // get data from pots
  phInc = (analogRead(A3) / 1000.0) + 0.25;
  grainsize = analogRead(A6) * 4;
  density = (analogRead(A2) >> 8) + 1;
  feedback = analogRead(A1);
  cutoff = analogRead(A5) >> 4;
  lpf.setCutoffFreq(cutoff);
  lpf2.setCutoffFreq(cutoff);
  lpf.setResonance(255 - cutoff);
  lpf2.setResonance(255 - cutoff);

  // set phase inceremnts and reset accumulators
  phAcc += phInc;
  if (phAcc >= grainsize) {
    phAcc = 0;
  }

  /*phAcc2 += phInc;
  if (phAcc2 >= 11025 + grainsize) {
    phAcc2 = 11025;
  }

  phAcc3 += phInc;
  if (phAcc3 >= 22050 + grainsize) {
    phAcc3 = 22050;
  }

  phAcc4 += phInc;
  if (phAcc4 >= 33075 + grainsize) {
    phAcc4 = 33075;
  }*/

  // sum up 16 grains to 4 groups
  /*int a1 = buffer[(int)phAcc];
  int a2 = buffer[(int)phAcc2];
  int a3 = buffer[(int)phAcc3];
  int a4 = buffer[(int)phAcc4];
  int a = (a1 + a2 + a3 + a4) / 4;

  int b1 = buffer[(int)phAcc + (100 * density)];
  int b2 = buffer[(int)phAcc2 + (100 * density)];
  int b3 = buffer[(int)phAcc3 + (100 * density)];
  int b4 = buffer[(int)phAcc4 - (100 * density)];
  int b = (b1 + b2 + b3 + b4) / 4;

  int c1 = buffer[(int)phAcc + (130 * density)];
  int c2 = buffer[(int)phAcc2 + (150 * density)];
  int c3 = buffer[(int)phAcc3 + (170 * density)];
  int c4 = buffer[(int)phAcc4 - (190 * density)];
  int c = (c1 + c2 + c3 + c4) / 4;

  int d1 = buffer[(int)phAcc + (120 * density)];
  int d2 = buffer[(int)phAcc2 + (160 * density)];
  int d3 = buffer[(int)phAcc3 + (146 * density)];
  int d4 = buffer[(int)phAcc4 - (187 * density)];
  int d = (d1 + d2 + d3 + d4) / 4;*/

  /*sigOutL = 0;
  sigOutR = 0;
  int divs = 44100 / density;
  for(int i = 0; i < density; i++) {

    sigOutL += buffer[(int) phAcc + (divs * i)];
    sigOutR += buffer[(int) phAcc + (divs * i) + (100*density)];
    
  }
  sigOutL = sigOutL / density;
  sigOutR = sigOutR / density;
  sigOutL = lpf.next(sigOutL);
  sigOutR = lpf2.next(sigOutR);*/

  int a = buffer[(int) phAcc];
  int b = buffer[(int) phAcc];
  int c = buffer[(int) phAcc + (density * 1000)];
  int d = buffer[(int) phAcc + (density * 1700)];

  sigOutL = lpf.next((a + c) / 2);
  sigOutR = lpf2.next((b + d) / 2);
  
  buffered = ((sigOutL + sigOutR) * feedback) >> 12;

  analogWrite(DAC0, sigOutL + 2047);
  analogWrite(DAC1, sigOutR + 2047);
}
