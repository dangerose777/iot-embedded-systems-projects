#include <Arduino.h>

// PIN DEFINITIONS
const int trigPin = 16;
const int echoPin = 33;
const int ledPin = 32;

// SETUP
void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 | Testing HC-SR04 Sensor");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

// LOOP
void loop() {
  Serial.println("Working...");

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2.0;
  if (duration == 0) Serial.println("Out of range");
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

    if(distance < 10)
    {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }

  delay(200);
}