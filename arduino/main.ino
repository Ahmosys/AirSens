/* Libs */
#include "Air_Quality_Sensor.h"

/* Variables */
#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 11
#define BUZZER_PIN 2

/* Color code RGB */
const byte COLOR_BLACK = 0b000;
const byte COLOR_RED = 0b100;
const byte COLOR_GREEN = 0b010;
const byte COLOR_BLUE = 0b001;
const byte COLOR_MAGENTA = 0b101;
const byte COLOR_CYAN = 0b011;
const byte COLOR_YELLOW = 0b110;
const byte COLOR_WHITE = 0b111;

/* Instantiation */
AirQualitySensor sensor(A0);

void setup() {

  Serial.begin(9600);

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  isSensorReady(sensor);

}

/* Main loop */
void loop() {

  // emitBuzzerSound();
  int airQuality = sensor.slope();

  Serial.print("Sensor value: ");
  Serial.println(sensor.getValue());

  if (airQuality == AirQualitySensor::FORCE_SIGNAL) {
     displayColorLed(COLOR_RED);
     Serial.println("High pollution! Force signal active.");
  } else if (airQuality == AirQualitySensor::HIGH_POLLUTION) {   
    displayColorLed(COLOR_RED);
    // emitBuzzerSound();
    Serial.println("High pollution!");
  } else if (airQuality == AirQualitySensor::LOW_POLLUTION) {
    displayColorLed(COLOR_YELLOW);
    Serial.println("Low pollution!");
  } else if (airQuality == AirQualitySensor::FRESH_AIR) {
     displayColorLed(COLOR_BLUE);
     Serial.println("Fresh air.");
 }
  
}

void turnOffLed() {
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_BLUE_PIN, LOW);
  digitalWrite(LED_RED_PIN, LOW);
}

void displayColorLed(byte color) {
  digitalWrite(LED_RED_PIN, bitRead(color, 2));
  digitalWrite(LED_GREEN_PIN, bitRead(color, 1));
  digitalWrite(LED_BLUE_PIN, bitRead(color, 0));
}

void emitStartupSignal() {
  displayColorLed(COLOR_GREEN);
  tone (BUZZER_PIN, 100, 1000);
  delay(1000);
  turnOffLed();
  delay(1000);
}

void emitBuzzerSound() {
  tone (BUZZER_PIN, 2000, 1000);
  delay(1500);
  noTone(BUZZER_PIN);
}

void isSensorReady(AirQualitySensor sensor) {
  if (sensor.init()) {
    emitStartupSignal();
  } else {
    Serial.println("Sensor ERROR!");
  }
}