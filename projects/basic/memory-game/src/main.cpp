#include <Arduino.h>

// PIN DEFINITIONS
const int ledPins[4] = {4, 16, 17, 23};
const int buttonPins[4] = {14, 27, 26, 25};

// GAME VARIABLES
const int sequenceLength = 5;
int sequence[sequenceLength];
int userInput[sequenceLength];
int currentRound = 0;

// FUNCTIONS PROTOTYPES
void playSequence(int round);
bool getUserSequence(int round);
int waitForButtonPress();
void resetGame();
void showStartEffect();
void showWinEffect();
void showLoseEffect();
void start();

// SETUP
void setup() {
  Serial.begin(115200);
  Serial.println("Memory Game");
  
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  randomSeed(analogRead(0)); // read noise from an unconnected pin 
  resetGame();
  start();
}

// MAIN LOOP
void loop() {
  delay(1000);

  Serial.print("Round ");
  Serial.println(currentRound);

  playSequence(currentRound);

  bool correct = getUserSequence(currentRound);

  if (!correct) {
    Serial.println("Wrong! Game Over.");
    showLoseEffect();
    
    Serial.println("Press any button to restart.");
    waitForButtonPress();
    resetGame();
    showStartEffect();

    return;
  }
  Serial.println("Correct!");
  currentRound++;

  if (currentRound > sequenceLength) {
    Serial.println("Congratulations! You Win!");
    showWinEffect();

    Serial.println("Press any button to play again.");
    waitForButtonPress();
    resetGame();
    showStartEffect();

    return;
  }
}

// GAME FUNCTIONS

void playSequence(int round) {
  for (int i = 0; i < round; i++) {
    int ledIndex = sequence[i];

    digitalWrite(ledPins[ledIndex], HIGH);
    delay(500);
    digitalWrite(ledPins[ledIndex], LOW);
    delay(200);
  }
}

bool getUserSequence(int round) {
  for (int i = 0; i < round; i++) {
    int pressedButton = waitForButtonPress();
    userInput[i] = pressedButton;

    digitalWrite(ledPins[pressedButton], HIGH);
    delay(300);
    digitalWrite(ledPins[pressedButton], LOW);

    if (userInput[i] != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForButtonPress() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(50); // debounce delay
        while (digitalRead(buttonPins[i]) == LOW);
        return i;
      }
    }
  }
}

void resetGame() {
  currentRound = 1;

  for (int i = 0; i < sequenceLength; i++) {
    sequence[i] = random(0, 4);
  }
}

void showStartEffect() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(200);

    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(200);
  }
}

void showWinEffect() {
  int numOfLeds = sizeof(ledPins) / sizeof(ledPins[0]);

  //r = repeat
  for (int r = 0; r < 4; r++) {
    for (int i = 0; i < numOfLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      digitalWrite(ledPins[i], LOW);
    }

    for (int i = numOfLeds -1; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(100);
      digitalWrite(ledPins[i], LOW);
    }
    delay(100);
  }
}

void showLoseEffect() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], HIGH);
    }

    delay(500);
    for (int j = 0; j < 4; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(500);
  }
}

void start() {
  Serial.println("Press any button to start.");
  waitForButtonPress();
  showStartEffect();
}