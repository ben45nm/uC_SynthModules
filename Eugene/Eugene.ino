byte counterA, counterB, counterC, counterD = 1;
byte seqA, seqB, seqC, seqD, lngA, lngB, lngC, lngD, stpA, stpB, stpC, stpD, offA, offB, offC, offD, davelombardo;
boolean gateA, gateB, gateC, gateD;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  gateA, gateB, gateC, gateD = false;
  seqA, seqB, seqC, seqD = 0;
}

void loop() {
  lngA = (analogRead(A4) >> 6)+1;
  lngB = (analogRead(A5) >> 6)+1;
  lngC = (analogRead(A6) >> 6)+1;
  lngD = (analogRead(A7) >> 6)+1;
  stpA = (analogRead(A8) >> 6)+1;
  stpB = (analogRead(A9) >> 6)+1;
  stpC = (analogRead(A10) >> 6)+1;
  stpD = (analogRead(A11) >> 6)+1;
  offA = analogRead(A12) >> 7;
  offB = analogRead(A13) >> 7;
  offC = analogRead(A14) >> 7;
  offD = analogRead(A15) >> 7;

  davelombardo = analogRead(A3) >> 2;

  // calculate line A
  if (analogRead(A0)>128 && !gateA) {

    if(analogRead(A2) > 128) {
      counterA, counterB, counterC, counterD = 1;
    }
    
    // counter
    counterA++;
    if(counterA > lngA) { counterA = 1; };
    if(random(255) < davelombardo && counterA > lngA/2) {
      stpA = stpA * 2;
    }
    seqA = (counterA + offA) * stpA;
    seqA = seqA % lngA;
    if(seqA < stpA) {
       digitalWrite(2, HIGH); 
    }
    gateA = true;
  }
  if (analogRead(A0)<128 && gateA) {
    gateA = false;
    digitalWrite(2, LOW);
  }

  // calculate line B
  if (analogRead(A0)>128 && !gateB) {
    // counter
    counterB++;
    if(counterB > lngB) { counterB = 1; };
    if(random(255) < davelombardo && counterB > lngB/2) {
      stpB = stpB * 2.5;
    }
    seqB = (counterB + offB) * stpB;
    seqB = seqB % lngB;
    if(seqB < stpB) {
       digitalWrite(3, HIGH); 
    }
    gateB = true;
  }
  if (analogRead(A0)<128 && gateB) {
    gateB = false;
    digitalWrite(3, LOW);
  }
}

