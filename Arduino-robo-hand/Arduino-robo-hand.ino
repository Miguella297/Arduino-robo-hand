#include <Servo.h>

Servo servoA;
Servo servoB;

const int servoAPin = 8;
const int servoBPin = 9;

const int stepDelay = 20;

void setup() {
  servoA.attach(servoAPin);
  servoA.write(0);   // immediately set starting position, no neutral snap

  servoB.attach(servoBPin);
  servoB.write(0);   // same fix here

  delay(300); // brief pause to let both servos settle at 0 before moving

  for (int pos = 0; pos <= 180; pos++) {
    servoA.write(pos);
    delay(stepDelay);
  }
  for (int pos = 180; pos >= 0; pos--) {
    servoA.write(pos);
    delay(stepDelay);    
  }

  for (int pos = 0; pos <= 180; pos++) {
    servoB.write(pos);
    delay(stepDelay);
  }
  for (int pos = 180; pos >= 0; pos--) {
    servoB.write(pos);
    delay(stepDelay);
  }
}

void loop() {
}