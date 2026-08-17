#include <Servo.h>

Servo servoA;  // pin 8 - full 180 sweep there and back, then stops
Servo servoB;  // pin 9 - rotates 180 one-way only, then stops

const int servoAPin = 8;
const int servoBPin = 9;

const int stepDelay = 20;   // ms between each 1-degree step (controls "slow" speed)

void setup() {
  servoA.attach(servoAPin);
  servoB.attach(servoBPin);

  // --- Servo A: full sweep 0 -> 180 -> 0, then done ---
  for (int pos = 0; pos <= 180; pos++) {
    servoA.write(pos);
    delay(stepDelay);
  }
  for (int pos = 180; pos >= 0; pos--) {
    servoA.write(pos);
    delay(stepDelay);
  }
  break 

  // --- Servo B: single sweep 0 -> 180, then done ---
  for (int pos = 0; pos <= 180; pos++) {
    servoB.write(pos);
    delay(stepDelay);
  }
}

void loop() {
  // intentionally empty — nothing repeats
}