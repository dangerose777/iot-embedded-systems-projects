#include <Arduino.h>

// PIN DEFINITIONS
const int ledPinBlue = 4;
const int ledPinRed = 18;
const int ledPinGreen = 21;

const int buttonPin = 27;
int buttonState = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("FreeRTOS Tests");
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  digitalWrite(ledPinBlue, HIGH);
  digitalWrite(ledPinRed, LOW);
  delay(1000);
  digitalWrite(ledPinBlue, LOW);
  digitalWrite(ledPinRed, HIGH);
  delay(1000);

  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW) {
    digitalWrite(ledPinGreen, HIGH);
  } else {
    digitalWrite(ledPinGreen, LOW);
  }
}