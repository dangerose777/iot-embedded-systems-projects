#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

// PIN DEFINITIONS
const int ledPin = 32;

// FUNCTIONS PROTOTYPES
void checkMacAddress();

// SETUP
void setup() {
  Serial.begin(115200);
  Serial.println("ESP32-NOW Wifi Connection | DevKit v1 - Diode LED");
  WiFi.mode(WIFI_STA);

  checkMacAddress();
}

// MAIN LOOP
void loop() {
  Serial.println("Working");
  delay(5000);
}

// FUNCTIONS

void checkMacAddress() {
  Serial.println("MAC Address: " + WiFi.macAddress());
}