#include "patterns.h"

boolean gate;
byte counter, base, spread, reset;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  counter = 0;
  gate = false;
}

void loop() {

  base = analogRead(A7) >> 6;
  spread = analogRead(A6) >> 6;
  reset = analogRead(A5) >> 5;

  if (counter > 31 || counter > reset) {
    counter = 0;
  }

  if (analogRead(A0) > 512 && !gate) {

    digitalWrite(13, bdArray[base][counter]);
    digitalWrite(14, snArray[(base + spread) % 16][counter]);
    digitalWrite(15, hhArray[(base + (spread * 2)) % 16][counter]);

    gate = true;
    counter++;
  }

  if (analogRead(A0) < 512 && gate) {
    gate = false;
  }

}
