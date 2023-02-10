uint16_t gate_trsh = 150;
boolean gateIn;

void setup() {
  // put your setup code here, to run once:
  gateIn, gateOutL, gateOutR = false;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (analogRead(A0) >= gate_trsh && !gateIn) {

    if (analogRead(A1) >= random(0, 1023)) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    } else {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    }
    gateIn = true;
    
  }

  if (analogRead(A0) < gate_trsh && gateIn) {
    
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    gateIn = false;

  }

}
