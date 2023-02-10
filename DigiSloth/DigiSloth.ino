/*  Slow random cv generator using Mozzi sonification library.
 *   Mozzis HIFI-Mode must be enabled for the PWM trick.
 *  Outputs three independent, randomly changing voltages.
 *  
 *  Using Mozzi sonification library by Tim Barrass: http://sensorium.github.com/Mozzi/
 *  
 *  ben @ 45nm, 2017.
*/

#include <MozziGuts.h>
#include <Oscil.h> //
#include <tables/sin2048_int8.h>
#include <mozzi_rand.h>

const byte A_PIN = 3;
const byte B_PIN = 4;
const byte C_PIN = 5;

byte a, b, c;
float freqA, freqB, freqC;

Oscil <SIN2048_NUM_CELLS, CONTROL_RATE> sinA(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, CONTROL_RATE> sinB(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, CONTROL_RATE> sinC(SIN2048_DATA);

void updatePins(byte a, byte b, byte c) {
  static byte a_count = 0;
  static byte b_count = 85;
  static byte c_count = 170;
  (a_count++ >= a) ? PORTD &= ~(1 << A_PIN) : PORTD |= (1 << A_PIN);
  (b_count++ >= b) ? PORTD &= ~(1 << B_PIN) : PORTD |= (1 << B_PIN);
  (c_count++ >= c) ? PORTD &= ~(1 << C_PIN) : PORTD |= (1 << C_PIN);
}

void setup() {
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  sinA.setFreq(0.01f);
  sinB.setFreq(0.006f);
  sinC.setFreq(0.008f);
  startMozzi(1024);
}

void updateControl() {
  
  int timeValue = map(mozziAnalogRead(A1), 0, 1023, 3000, 30000);
  
  if (sinA.next() == 0 || sinA.next() == 100 || sinA.next()  == -100) {
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeA = rand(minTime, maxTime);
    int x = rand(0, 50);
    freqA = (float) x / timeA;
    sinA.setFreq(freqA);
  }

  if (sinB.next() == 0 || sinB.next() == 100 || sinB.next() == -100) {
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeA = rand(minTime, maxTime);
    int x = rand(0, 60);
    freqB = (float) x / timeA;
    sinB.setFreq(freqB);
  }

  if (sinC.next() == 0 || sinC.next() == 100) {
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeA = rand(minTime, maxTime);
    int x = rand(0, 45);
    freqC = (float) x / timeA;
    sinC.setFreq(freqC);
  }

  a = 128 + sinA.next();
  b = 128 + sinB.next();
  c = 128 + sinC.next();

}

int updateAudio() {
  updatePins(a, b, c);
  return 0;
}

void loop() {
  audioHook();
}

