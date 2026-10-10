#include <Arduino.h>

volatile int buttonPin = 5;

volatile unsigned long interruptCount = 0;
unsigned long prevCount = 0;

void stateChange() {
  interruptCount++;
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  
 attachInterrupt(digitalPinToInterrupt(buttonPin), stateChange, FALLING);
}

void loop() {

  
 if (interruptCount != prevCount) {
     Serial.printf(" %d\n", interruptCount);
    prevCount = interruptCount;
  }

}