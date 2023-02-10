int a, b, c, d;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
analogWriteResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  b = analogRead(A6) << 2;
  c = analogRead(A5) << 2;
  d = analogRead(A4) << 2;
a = random(b, c);

Serial.print("a: ");
Serial.print(a);
Serial.print(" b: ");
Serial.print(b);
Serial.print(" c: ");
Serial.print(c);
Serial.print(" d: ");
Serial.println(d);
analogWrite(A3, a);
delay(d);
}
