//#include "Crossfader.h"

int16_t valueA;
int16_t valueB;
int16_t output;
byte mode;
float timbre;

int16_t crossfade;
int16_t switching;
int16_t bitwise;
int16_t ampMod;

byte modes = 4;
byte ranges = modes - 1;

float p;

int16_t values[] = {crossfade, switching, bitwise, ampMod};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //mode = analogRead(A0) >> 9;
  p = analogRead(A0) / 4095 * modes;

  timbre = map(analogRead(A1), 0, 4095, 0, 100) / 100.0;
  valueA = analogRead(A2);
  valueB = analogRead(A3);

  doCrossfade();
  doSwitching();
  doBitwise();
  doAmpmod();
  analogWrite(DAC1, blend());
}

void doCrossfade() {
  crossfade = (valueA * timbre) + (valueB * (1 - timbre));
}

void doSwitching() {
  if (valueA >= ((int) timbre << 12)) {
    switching = valueA;
  } else {
    switching = valueB;
  }
}

void doBitwise() {
  bitwise = ((valueA ^ valueB) * timbre) + ((valueA & valueB) * (1 - timbre));
}

void doAmpmod() {
  ampMod = (valueA * timbre) + (((valueA * valueB) >> 12) * (1 - timbre));
}

int16_t blend() {

  int16_t out = 0;

  for (int i = 0; i <= ranges; i++) {

    out = out + (values[i] * (1 - p / modes)) + (values[i + 1] * (p / modes * i));

  }

  return out;

}
