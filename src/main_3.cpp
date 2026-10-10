#include <Arduino.h>

volatile int buttonPin = 5;

volatile unsigned long interruptCount = 0;
unsigned long prevCount = 0;

volatile bool hasChanged = false;


void IRAM_ATTR stateChange() {
  hasChanged = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  
 attachInterrupt(digitalPinToInterrupt(buttonPin), stateChange, FALLING);
}

void loop() {

  if (hasChanged) {
    hasChanged = false;
    if (digitalRead(buttonPin) == LOW) {
      interruptCount++;
    }
  }

  if (interruptCount != prevCount) {
     Serial.printf("%lu\n", interruptCount);
    prevCount = interruptCount;
  }

}