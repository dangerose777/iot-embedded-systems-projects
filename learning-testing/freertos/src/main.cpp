#include <Arduino.h>

// PIN DEFINITIONS
const int ledPinBlue = 4;
const int ledPinRed = 18;
const int ledPinGreen = 21;

const int buttonPin = 27;
int buttonState = 0;

// TASKS
void toggleLED(void *parameter)
{
  while(1) {
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinRed, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(ledPinBlue, LOW);
    digitalWrite(ledPinRed, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void buttonLED(void *parameter)
{
  while(1) {
    buttonState = digitalRead(buttonPin);
    if(buttonState == LOW) {
      digitalWrite(ledPinGreen, HIGH);
    } else {
      digitalWrite(ledPinGreen, LOW);
    }
  }
}

// SETUP
void setup() {
  // config
  Serial.begin(115200);
  Serial.println("FreeRTOS Tests");
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // task 1
  xTaskCreatePinnedToCore(
    toggleLED,       // task function
    "Toggle LED",    // name of task
    1024,            // stack size
    NULL,            // parameter to pass to function
    1,               // task priority
    NULL,            // task handle
    1                // core
  );

  //task 2
  xTaskCreatePinnedToCore(
    buttonLED,
    "Button LED",
    1024,
    NULL,
    1,
    NULL,
    1
  );
}

void loop() {

}