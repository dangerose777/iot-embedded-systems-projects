#include <Arduino.h>

const int ledPin = 26;
const int buttonPin = 25;
const int potPin = 32;

int potValue = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Tattoo Power Supply Prototype");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(100);
  
  //pot value = led brightness
}