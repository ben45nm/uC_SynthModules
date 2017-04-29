/*  Slow random cv generator using Mozzi sonification library.
 *   Mozzis HIFI-Mode must be enabled for the PWM trick.
 *  Outputs three independent, randomly changing voltages.
 *  
 *  Minimum time range 1s - 3s
 *  Maximum time range 10s - 30s
 *  
 *  Using Mozzi sonification library by Tim Barrass: http://sensorium.github.com/Mozzi/
 *  
 *  ben @ 45nm, 2017.
*/

#include <MozziGuts.h>
#include <Line.h>
#include <EventDelay.h>
#include <mozzi_rand.h>

Line <long> lineA, lineB, lineC;
EventDelay edA, edB, edC;
int minA, maxA, minB, maxB, minC, maxC;
#define CONTROL_RATE 1024

// LED pins, use 0-7 for PORTD, otherwise change to PORTB in updatePins
const byte A_PIN = 3;
const byte B_PIN = 4;
const byte C_PIN = 5;

void setup() {
  startMozzi(CONTROL_RATE);
  // on startup set default values to work with
  minA, maxA, minB, maxB, minC, maxC = 0;
  pinMode(A_PIN,OUTPUT);
  pinMode(B_PIN,OUTPUT);
  pinMode(C_PIN,OUTPUT);
}

void loop() {
  audioHook();
}

void updateControl() {

  // read pot value and map it to milliseconds/seconds (2s -20s)
  int timeValue = map(mozziAnalogRead(A1), 0, 1023, 2000, 20000);

  // will run/be ready when the previous line has ended
  if (edA.ready()) {
    minA = maxA; // set new min to the previous max value
    maxA = rand(0, 255); // set new max value

    // calculate a range from pot value to calculate pseudo random line timing
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeA = rand(minTime, maxTime);
    
    edA.set(timeA); // set length of next line to event delay timing
    lineA.set(minA, maxA, ms2steps(timeA)); // set line values (start value, end value, steps)
    edA.start(); // start event delay
  }

  if (edB.ready()) {
    minB = maxB;
    maxB = rand(0, 255);
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeB = rand(minTime, maxTime);
    edB.set(timeB);
    lineB.set(minB, maxB, ms2steps(timeB));
    edB.start();
  }

  if (edC.ready()) {
    minC = maxC;
    maxC = rand(0, 255);
    int minTime = (int) timeValue * 0.5;
    int maxTime = (int) timeValue * 1.5;
    int timeC = rand(minTime, maxTime);
    edC.set(timeC);
    lineC.set(minC, maxC, ms2steps(timeC));
    edC.start();
  }

  // update pins with actual values from the lines
  updatePins(lineA.next(), lineB.next(), lineC.next());

}

// convert milliseconds to steps @ control rate
int ms2steps(int ms) {
  return (int) (ms / 1000) * CONTROL_RATE;
}

void updatePins(byte a, byte b, byte c){
  // stagger pwm counter starts to try to reduce combined flicker
  static byte a_count=0;
  static byte b_count=85;
  static byte c_count=170;
  // PORTD maps to Arduino digital pins 0 to 7
  (a_count++ >= a) ? PORTD &= ~(1 << A_PIN) : PORTD |= (1 << A_PIN);
  (b_count++ >= b) ? PORTD &= ~(1 << B_PIN) : PORTD |= (1 << B_PIN);
  (c_count++ >= c) ? PORTD &= ~(1 << C_PIN) : PORTD |= (1 << C_PIN);
}

int updateAudio() {
  return 0; // do nothing
}
