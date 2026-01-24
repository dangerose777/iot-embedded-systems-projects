#include <Arduino.h>

// PIN DEFINITIONS
const int ledPin = 4;

void setup() {
  Serial.begin(115200);
  Serial.println("FreeRTOS Tests");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Serial.println("Led ON");
  // digitalWrite(ledPin, HIGH);
  // delay(1000);
  // Serial.println("Led OFF");
  // digitalWrite(ledPin, LOW);
  // delay(1000);
}