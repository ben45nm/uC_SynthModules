int counter = 1;
int lineA, lineB, lineC, offset, a, b;
boolean gate;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  gate = false;
  lineA, lineB, lineC = 0;
}

void loop() {
  a = (analogRead(A7) >> 6)+1;
  b = (analogRead(A6) >> 6)+1;
  offset = analogRead(A5) >> 7;
  
  if (analogRead(A0)>128 && !gate) {
    // counter
    counter++;
    if(counter > 16) { counter = 1; };
    
    // calculate line A
    lineA = (counter) * a;
    lineA = lineA % 16;
    if(lineA < a) {
       digitalWrite(2, HIGH); 
    }
    
    // calculate line B
    lineB = (counter+offset) * b;
    lineB = lineB % 16;
    if(lineB < b) {
       digitalWrite(3, HIGH); 
    }
    
    // calculate line C
    if(lineA >= a && lineB >= b) {
      digitalWrite(4, HIGH);
    }
    
    gate = true;
  }
  
  if (analogRead(A0)<128 && gate) {
    gate = false;
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
}

