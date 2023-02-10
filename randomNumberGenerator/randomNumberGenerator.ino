boolean gateA, gateB;

void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  gateA = false;
  gateB = false;
}

void loop() {

  if (analogRead(A0) > 512 && !gateA) {

    int state0 = random(0, 2);
    if (state0 > 0) {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(2, LOW);
    }

    int state1 = random(0, 2);
    if (state1 > 0) {
      digitalWrite(3, HIGH);
    } else {
      digitalWrite(3, LOW);
    }

    int state2 = random(0, 2);
    if (state2 > 0) {
      digitalWrite(4, HIGH);
    } else {
      digitalWrite(4, LOW);
    }

    int state3 = random(0, 2);
    if (state3 > 0) {
      digitalWrite(5, HIGH);
    } else {
      digitalWrite(5, LOW);
    }

    int state4 = random(0, 2);
    if (state4 > 0) {
      digitalWrite(6, HIGH);
    } else {
      digitalWrite(6, LOW);
    }
    gateA = true;

  }
  if (analogRead(A0) < 256 && gateA) {
    gateA = false;
  }

  /////////

    if (analogRead(A3) > 256 && !gateB) {

    int state5 = random(0, 2);
    if (state5 > 0) {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }

    int state6 = random(0, 2);
    if (state6 > 0) {
      digitalWrite(8, HIGH);
    } else {
      digitalWrite(8, LOW);
    }

    int state7 = random(0, 2);
    if (state7 > 0) {
      digitalWrite(9, HIGH);
    } else {
      digitalWrite(9, LOW);
    }

    int state8 = random(0, 2);
    if (state8 > 0) {
      digitalWrite(10, HIGH);
    } else {
      digitalWrite(10, LOW);
    }

    int state9 = random(0, 2);
    if (state9 > 0) {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }
    gateB = true;

  }
  if (analogRead(A3) < 512 && gateB) {
    gateB = false;
  }

}


