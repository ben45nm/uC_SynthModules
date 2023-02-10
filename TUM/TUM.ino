//#include "LedControl.h"

#define CLOCK (A0)
#define PROB (A7)
#define LENGTH (A6)

//LedControl lc=LedControl(12,11,10,1);

boolean gate;
int prob, leng, counter;

int tArray[32] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int tmpArray[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int dacArray[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int pwmPin = 5;
int gatePin = 7;

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(gatePin, OUTPUT);
  digitalWrite(pwmPin, LOW);
  digitalWrite(gatePin, LOW);
  gate = false;
  counter = 1;
  Serial.begin(19200);
  //lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  //lc.setIntensity(0,8);
  /* and clear the display */
  //lc.clearDisplay(0);
}

void loop() {

  prob = map(analogRead(PROB), 0, 1023, 0, 100);
  //leng = analogRead(LENGTH) >> 5;
  leng = 16;

  if (analogRead(CLOCK) > 512 && !gate) {
    //lc.setLed(0, 0, 0, true);
    //Serial.println("clock");

    //counter
    if (counter == leng) {
      counter = 0;
    }


Serial.println("T: "+counter);

    gate = true;
    counter++;
  }
  if (analogRead(CLOCK) < 512 && gate) {
    //lc.setLed(0, 0, 0, false);
    gate = false;
  }


}

int b2int() {
  int result = 0;
  for (int i = 0; i < 8; i++) {
    result += dacArray[i] * (1 << (7 - i));
  }
  return result;
}

