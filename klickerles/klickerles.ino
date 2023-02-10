byte bd_grid[4][16] = {
  {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1}
};

byte sn_grid[4][16] = {
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
};

byte hh_grid[4][16] = {
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0}
};

boolean mainGate, gateA, gateB, gateC;
byte mainCounter, counterA, divA, rndA, counterB, divB, rndB, counterC, divC, rndC;

void setup() {
  // put your setup code here, to run once:
  mainCounter, counterA, counterB, counterC = 0;
  mainGate, gateA, gateB, gateC = false;

}

void loop() {
  if (analogRead(A0) > 512 && !mainGate) {

    if (mainCounter > 15) {
      mainCounter = 0;
    }

    divA = analogRead(A7) >> 7;
    rndA = analogRead(A6) >> 2;
    divB = analogRead(A5) >> 7;
    rndB = analogRead(A4) >> 2;

    if ((mainCounter % (divA + 1)) == 0) {
      processA();
    }

    if ((mainCounter % (divB + 1)) == 0) {
      processB();
    }

    processC();

    voltage1();
    voltage2();

    mainGate = true;
    mainCounter++;
  }

  if (analogRead(A0) < 512 && mainGate) {

    mainGate = false;
  }

}

void processA() {

  if (counterA > 15) {
    counterA = 0;
  }

  byte destGrid = 0;
  if (counterA == 0) {
    destGrid = random(0, 3);
  }
  byte randomNumberA = random(0, 255);

  if (randomNumberA < rndA) {
    int randomGate = random(0, 1);
    if (randomGate == 0) {
      digitalWrite(3, LOW);
      gateA = false;
    } else {
      digitalWrite(3, HIGH);
      gateA = true;
    }
  } else {
    if (bd_grid[destGrid][counterA] == 0) {
      digitalWrite(3, LOW);
      gateA = false;
    } else {
      digitalWrite(3, HIGH);
      gateA = true;
    }
  }

  counterA++;
}

void processB() {

  if (counterB > 15) {
    counterB = 0;
  }

  byte destGrid = 0;
  if (counterB == 0) {
    destGrid = random(0, 3);
  }
  byte randomNumberB = random(0, 255);

  if (randomNumberB < rndB) {
    int randomGate = random(0, 1);
    if (randomGate == 0) {
      digitalWrite(4, LOW);
      gateB = false;
    } else {
      digitalWrite(4, HIGH);
      gateB = true;
    }
  } else {
    if (sn_grid[destGrid][counterB] == 0) {
      digitalWrite(4, LOW);
      gateB = false;
    } else {
      digitalWrite(4, HIGH);
      gateB = true;
    }
  }

  counterB++;
}

void processC() {

  if (counterC > 15) {
    counterC = 0;
  }

  byte destGrid = 0;
  if (counterC == 0) {
    destGrid = random(0, 3);
  }
  if (hh_grid[destGrid][counterC] == 0) {
    digitalWrite(5, LOW);
    gateC = false;
  } else {
    digitalWrite(5, HIGH);
    gateC = true;
  }
  
  counterC++;
}

void voltage1() {

  if (gateA && gateB) {
    byte voltA = random(0, 255);
  }

}

void voltage2() {

  if (gateB && gateC) {
    byte voltB = random(0, 255);
  }

}
