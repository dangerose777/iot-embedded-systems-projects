#include <Arduino.h>

// PIN DEFINITIONS
const int vrXPin = A0;
const int vrYPin = A1;
const int swPin = 2;

// SETUP
void setup() {
  Serial.begin(9600);
  Serial.println("Hello, World!");

  pinMode(swPin, INPUT_PULLUP);
}

// MAIN LOOP
void loop() {
  int x = analogRead(vrXPin);
  int y = analogRead(vrYPin);
  bool buttonPressed = (digitalRead(swPin) == LOW);

  // CONSOLE OUTPUT

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("| Y: ");
  Serial.print(y);
  Serial.print("| Button: ");
  Serial.println(buttonPressed ? "Pressed" : "Released");
  delay(500);
}

// connection with turtle program in python
// script | moving the joystick will move the turtle