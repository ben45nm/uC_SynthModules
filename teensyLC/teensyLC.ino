#include <avr/pgmspace.h>
const PROGMEM int16_t testarray[22050] = {};

void setup() {
  // put your setup code here, to run once:
for(int i = 0; i < 22050; i++){
  testarray[i] = random(0, 1024);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

