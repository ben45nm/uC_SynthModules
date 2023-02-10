#include <DueTimer.h>
#include "ReverbTank.h"
#include "IntMap.h"
//#include <ffnmpatterns.h>

#define REC_PIN 7
#define REV_PIN 8

#define SAMPLE_RATE 11025.0
#define SAMPLES_PER_CYCLE 22050 //?
#define SAMPLES_PER_CYCLE_FIXEDPOINT (SAMPLES_PER_CYCLE<<20)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)

int16_t bufferA[22050];
int16_t bufferB[22050];
uint16_t writerA, reader;
uint16_t pos, gsize, freq, densAdd;
byte density;
boolean record, reverse;
ReverbTank reverb;
const IntMap gsizeMap(0,4095,100,22050);
const IntMap posMap(0,4095,0,22049);
//const IntMap freqMap(0,4095,50,3520);

void setup() {
  pinMode(REC_PIN, INPUT);
  digitalWrite(REC_PIN, LOW);
  pinMode(REV_PIN, INPUT);
  digitalWrite(REV_PIN, LOW);
  writerA, reader = 0;
  analogReadResolution(12);
  Timer2.attachInterrupt(readPots).setFrequency(3906).start();
  Timer0.attachInterrupt(readAudioInput).setFrequency(91).start();
  Timer1.attachInterrupt(playGrain).setFrequency(91).start();
  record = false;
  reverse = false;
}

void loop() {
}

void readPots() {

  record = digitalRead(REC_PIN);
  reverse = digitalRead(REV_PIN);
  gsize = gsizeMap(analogRead(A2));
  pos = posMap(analogRead(A3));
  //freq = freqMap(analogRead(A4));
  freq = analogRead(A4) + 50;
  density = (analogRead(A7) >>8) + 1;
  Timer1.setFrequency(1 / freq * 1000000);
  densAdd = 22050 / density;
  
}

void readAudioInput() {

  if (writerA == 22050) {
    writerA = 0;
  }
  if(record) {
    bufferA[writerA] = analogRead(A0) - 2047;
    bufferB[writerA] = analogRead(A1) - 2047;
  }
  writerA++;

}

void playGrain() {
  
  if(reader == gsize || reader == 0 - gsize) {
    reader = 0;
  }

  int16_t sumLeft, sumRight = 0;

  for (int i = 1; i < density; i++) {
    //sumLeft += bufferA[reader + (pos % 22500) + (22500 / density * i)];
    sumLeft += bufferA[reader + (pos % 22500) + (densAdd * i)] * sin(((reader/gsize) * 3.1415));
    sumRight += bufferB[reader + (pos % 22500) + (densAdd * i)] * sin(((reader/gsize) * 3.1415));
  }
  
  analogWrite(DAC0, reverb.next(sumLeft) + 2047);
  analogWrite(DAC1, reverb.next(sumRight) + 2047);
  if(reverse) {
    reader--;
  } else {
    reader++;
  }
  
}
