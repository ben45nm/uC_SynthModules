#include <DueTimer.h>
#include "LowPassFilterDue.h"
#include "ReverbTank.h"

#define REC_PIN 7

uint16_t bufferA[22050];
uint16_t bufferB[22050];
uint16_t writerA, reader;
uint16_t pos, gsize, density, freq, cutoff, reso;
boolean recEnabled;

ReverbTank reverb;

LowPassFilterDue lpfL;
LowPassFilterDue lpfR;

void setup() {
  pinMode(REC_PIN, INPUT);
  digitalWrite(REC_PIN, LOW);
  writerA, reader = 0;
  Timer0.attachInterrupt(readAudioInput).setFrequency(11025).start();
  Timer1.attachInterrupt(playGrain).setFrequency(11025).start();
}

void loop() {

  recEnabled = digitalRead(REC_PIN);
  gsize = map(analogRead(A2), 0, 1023, 100, 22050);
  pos = map(analogRead(A3), 0, 1023, 0, gsize-100);
  freq = map(analogRead(A4), 0, 1023, 2500, 18000);
  density = map(analogRead(A7), 0, 1023, 1, 12);

  cutoff = analogRead(A5) >> 2;
  reso = analogRead(A6) >> 2;

  lpfL.setCutoffFreq(cutoff);
  lpfL.setResonance(reso);
  lpfR.setCutoffFreq(cutoff);
  lpfR.setResonance(reso);

  Timer1.setFrequency(freq);

}

void readAudioInput() {

  if (writerA == 22050) {
    writerA = 0;
  }
  if(recEnabled) {
    bufferA[writerA] = analogRead(A0);
    bufferB[writerA] = analogRead(A1);
  }
  writerA++;

}

void playGrain() {
  
  if(reader == gsize) {
    reader = 0;
  }

  int sumLeft, sumRight = 0;

  for (int i = 1; i < density; i++) {
    sumLeft += bufferA[reader + (pos % 22500) + (22500 / density * i)];
    sumRight += bufferB[reader + (pos % 22500) + (22500 / density * i)];
  }
  
  analogWrite(DAC0, reverb.next(lpfL.next(sumLeft)));
  analogWrite(DAC1, reverb.next(lpfR.next(sumRight)));
  reader++;
  
}
