#include <Servo.h>

Servo servoA;
Servo servoB;

const int servoAPin = 8;
const int servoBPin = 9;

const int stepDelay = 20;

void setup() {
  servoA.attach(servoAPin);
  servoA.write(0);     // starting position

  servoB.attach(servoBPin);
  servoB.write(90);    // starting position

  delay(300); // let both servos settle before moving

  // --- Servo A: 0 -> 180 -> 0 ---
  for (int pos = 0; pos <= 180; pos++) {
    servoA.write(pos);
    delay(stepDelay);
  }
  for (int pos = 180; pos >= 0; pos--) {
    servoA.write(pos);
    delay(stepDelay);
  }

  // --- Servo B: 90 -> 0 -> 90 ---
  for (int pos = 90; pos >= 0; pos--) {
    servoB.write(pos);
    delay(stepDelay);
  }
  for (int pos = 0; pos <= 90; pos++) {
    servoB.write(pos);
    delay(stepDelay);
  }
}

void loop() {
}
