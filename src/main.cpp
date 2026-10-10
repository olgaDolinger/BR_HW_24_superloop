#include <Arduino.h>

const int LED1_PIN = 4;
const int LED2_PIN = 5;
const int LED3_PIN = 6;

const unsigned long LED1_BLINK_DURATION = 1000;
const unsigned long LED2_BLINK_DURATION = 3000;
const unsigned long LED3_BLINK_DURATION = 6000;

struct Led {
    uint8_t pin;
    bool on;
    uint32_t previousMillis;
    uint32_t duration_ms;
};

unsigned long previousMillis = 0;
const unsigned long SERIAL_INTERVAL = 200;  // Інтервал виведення (200 мс)

void updateLed(Led* led, unsigned long currentMillis) {
    if (currentMillis - led->previousMillis >= led->duration_ms) {
        led->on = !led->on;
        digitalWrite(led->pin, led->on ? HIGH : LOW);
        led->previousMillis = currentMillis;
    }
}

Led led1 = {LED1_PIN, false, 0, LED1_BLINK_DURATION};
Led led2 = {LED2_PIN, false, 0, LED2_BLINK_DURATION};
Led led3 = {LED3_PIN, false, 0, LED3_BLINK_DURATION};

void setup() {
    Serial.begin(115200);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();

    updateLed(&led1, currentMillis);
    updateLed(&led2, currentMillis);
    updateLed(&led3, currentMillis);
}
