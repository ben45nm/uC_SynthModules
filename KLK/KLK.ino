#include <TimerOne.h>

byte bpm;
uint8_t mcs;

byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
byte counter1, counter4, counter8, counter6, counter3, counter2, counter16;
boolean useMidi;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  counter4 = 1;
  counter8 = 1;
  counter6 = 1;
  counter3 = 1;
  counter2 = 1;
  counter16 = 1;
  counter1 = 1;
  useMidi = false;
  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( sync );
  Serial.begin(31250);
}

void loop() {

  if (analogRead(A7) > 512) {
    useMidi = true;
  } else {
    useMidi = false;
  }

  if (useMidi) {
    if (Serial.available() > 0) {
      data = Serial.read();
      if (data == midi_start) {
        play_flag = 1;
      }
      else if (data == midi_continue) {
        play_flag = 1;
      }
      else if (data == midi_stop) {
        play_flag = 0;
      }
      else if ((data == midi_clock) && (play_flag == 1)) {
        sync();
      }
    }
  } else {
    bpm = map(analogRead(A6), 0, 1023, 1, 200);
    mcs = 60000 / bpm * 1000 / 24;
    Timer1.setPeriod(mcs);
  }
}

void sync() {

  // wholes
  if (counter1 > 96) {
    counter1 = 1;
  }
  if (counter1 <= 48) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }

  // halfs
  if (counter2 > 48) {
    counter2 = 1;
  }
  if (counter2 <= 24) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }

  // quarters
  if (counter4 > 24) {
    counter4 = 1;
  }
  if (counter4 <= 12) {
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
  }

  // eights
  if (counter8 > 12) {
    counter8 = 1;
  }
  if (counter8 <= 6) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  // sixteenths
  if (counter16 > 6) {
    counter16 = 1;
  }
  if (counter16 <= 3) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

  // thirds
  if (counter3 > 16) {
    counter3 = 1;
  }
  if (counter3 <= 8) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }

  // sixths
  if (counter6 > 8) {
    counter6 = 1;
  }
  if (counter6 <= 4) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }

  // random
  if (random(0, 50) > 100) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  counter4++;
  counter8++;
  counter3++;
  counter6++;
  counter16++;
  counter2++;
  counter1++;
}
