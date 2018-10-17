#include <HCSR04.h>
#include "pitches.h"

#define TRIGGER_PIN 0
#define ECHO_PIN 1
#define BUZZER_PIN 2
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
UltraSonicDistanceSensor distanceSensor(TRIGGER_PIN, ECHO_PIN);  // Initialize sensor that uses digital pins 13 and 12.

int duration, distance; //to measure the distance and time taken

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  distance = distanceSensor.measureDistanceCm();
  //when distance is greater than or equal to 200 OR less than or equal to 0,the BUZZER_PIN and LED are off
  if (distance >= MAX_DISTANCE)
  {
    noTone(BUZZER_PIN);
  }
  else {
    duration = 500;
    tone(BUZZER_PIN, NOTE_D4);
    delay(duration);
    noTone(BUZZER_PIN);
    delay(duration);
  }
}
