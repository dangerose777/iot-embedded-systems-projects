#include <Arduino.h>

// PIN DEFINITIONS
const int vrXPin = A0;
const int vrYPin = A1;
const int swPin = 2;

// SETUP
void setup() {
  Serial.begin(9600);
  Serial.println("Joystick Serial Monitor");

  pinMode(swPin, INPUT_PULLUP);
}

// MAIN LOOP
void loop() {
  int x = analogRead(vrXPin);
  int y = analogRead(vrYPin);
  bool btnPressed = (digitalRead(swPin) == LOW);

  // CONSOLE OUTPUT

  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(btnPressed ? 1 : 0);
  delay(100);
}