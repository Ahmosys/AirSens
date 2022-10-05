/* Libs */
#include "Air_Quality_Sensor.h"

/* Variables */
#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 11
#define BUZZER_PIN 2

bool isAlreadyEmitSound;
int airQuality = -1;


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

  int airQuality = sensor.slope();

  Serial.print("Sensor value: ");
  Serial.println(sensor.getValue());

  if (airQuality == AirQualitySensor::HIGH_POLLUTION || airQuality == AirQualitySensor::FORCE_SIGNAL) {
    displayColorLed(COLOR_RED);
    if (!isAlreadyEmitSound) {
      emitBuzzerSound();
    }
    Serial.println("High pollution! Force signal active.");
  } else if (airQuality == AirQualitySensor::LOW_POLLUTION) {
    displayColorLed(COLOR_YELLOW);
    Serial.println("Low pollution!");
    isAlreadyEmitSound = false;
    
  } else if (airQuality == AirQualitySensor::FRESH_AIR) {
    displayColorLed(COLOR_BLUE);
    Serial.println("Fresh air.");
 }

  delay(1000);

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
  for (int i=0; i < 5; i++) {
    tone (BUZZER_PIN, 100, 1000);
    delay(1500);
    noTone(BUZZER_PIN);
  }
  isAlreadyEmitSound = true;
}

void isSensorReady(AirQualitySensor sensor) {
  if (sensor.init()) {
    emitStartupSignal();
  } else {
    Serial.println("Sensor ERROR!");
  }
}
