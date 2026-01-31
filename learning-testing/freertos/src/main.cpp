#include <Arduino.h>

// PIN DEFINITIONS
// const int ledPinBlue = 4;
// const int ledPinRed = 18;
// const int ledPinGreen = 21;

// const int buttonPin = 27;
// int buttonState = 0;

// TASKS
void testTask(void *parameter) {
  while(1)
  {
    Serial.print("High water mark: ");
    Serial.println(uxTaskGetStackHighWaterMark(NULL));

    Serial.println("Heap before malloc (bytes): ");
    Serial.println(xPortGetFreeHeapSize());

    int *ptr = (int*)pvPortMalloc(1024 * sizeof(int));

    if (ptr == NULL) {
      Serial.println("Not enough heap");
    }
    else {
      //testing
      for(int i = 0; i < 1024; i++) {
        ptr[i] = 3;
      }
    }

    Serial.println("Heap before malloc (bytes): ");
    Serial.println(xPortGetFreeHeapSize());

    //free up allocated memory
    vPortFree(ptr);

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}


// SETUP
void setup() {
  // config
  Serial.begin(115200);
  Serial.println("FreeRTOS Tests");
  // pinMode(ledPinBlue, OUTPUT);
  // pinMode(ledPinRed, OUTPUT);
  // pinMode(ledPinGreen, OUTPUT);
  // pinMode(buttonPin, INPUT_PULLUP);

  // task 1
  xTaskCreatePinnedToCore(
    testTask,       // task function
    "Test Task",    // name of task
    1500,            // stack size
    NULL,            // parameter to pass to function
    1,               // task priority
    NULL,            // task handle
    1                // core
  );
}

void loop() {

}