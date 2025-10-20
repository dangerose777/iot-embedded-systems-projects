#include <Arduino.h>

// PIN DEFINITIONS
const int ledPin = 26;
const int btnPin = 25;
const int potPin = 32;

// SETTINGS
const float maxV = 10;
const int pwmChannel = 0;
const int pwmFreq = 5000;
const int pwmRes = 8;

// OUTPUT VARIABLES
bool buttonState = false;
float outputV = 0.0;

// SETUP
void setup() {
  Serial.begin(115200);
  Serial.println("Tattoo Power Supply Prototype");

  pinMode(btnPin, INPUT_PULLUP);
  pinMode(potPin, INPUT);
  ledcSetup(pwmChannel, pwmFreq, pwmRes);
  ledcAttachPin(ledPin, pwmChannel);
  
  ledcWrite(pwmChannel, 0);
}

// MAIN LOOP
void loop() {
  buttonState = digitalRead(btnPin) == LOW;
  int potValue = analogRead(potPin);
  float voltagePercent = (float)potValue / 4095.0;
  outputV = voltagePercent * maxV;  // visual voltage representation | not used to set real voltage on hardware

  if (buttonState) {
    int pwmValue = (int)(voltagePercent * 255.0);
    ledcWrite(pwmChannel, pwmValue);
  }
  else {
    ledcWrite(pwmChannel, 0);
  }

  // CONSOLE OUTPUT

  static unsigned long lastPrint = 0;
  
  if (millis() - lastPrint >= 500) {
    Serial.print("Button State: ");
    Serial.print(buttonState ? "ON" : "OFF");
    Serial.print(" | Output Voltage: ");
    Serial.print(outputV, 2);
    Serial.print("V");
    Serial.print(" | Potentiometer Value: ");
    Serial.print(potValue);
    Serial.println();
    lastPrint = millis();
  }
}