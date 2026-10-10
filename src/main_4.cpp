#include <Arduino.h>

volatile int buttonPin = 5;

volatile unsigned long interruptCount = 0;

unsigned long prevTime = 0;
unsigned long stateDelay = 5; 


unsigned long prevDebounceTime = 0;
unsigned long debounceDelay = 50; 

bool buttonIsPressed = false;   
int lastReading = HIGH;        


void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  
}

void loop() {

  unsigned long currentTime = millis();
  if (currentTime - prevTime >= stateDelay) {
    prevTime = currentTime;

    int reading = digitalRead(buttonPin);
    if (reading != lastReading) {
      lastReading = reading;
      prevDebounceTime = currentTime;
    }

    if (currentTime - prevDebounceTime >= debounceDelay) {
      if (reading == LOW && !buttonIsPressed) {
        buttonIsPressed = true;          
        interruptCount++;
        Serial.printf("%lu\n", interruptCount);
      } else if (reading == HIGH && buttonIsPressed) {
        buttonIsPressed = false;          
      }
    }
  }
}

