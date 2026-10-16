#include <AccelStepper.h>

AccelStepper xMotor(AccelStepper::DRIVER, 4, 5);
AccelStepper yMotor(AccelStepper::DRIVER, 2, 3);

void setup() {
  xMotor.setMaxSpeed(800);
  xMotor.setAcceleration(200);

  yMotor.setMaxSpeed(800);
  yMotor.setAcceleration(200);

  Serial.begin(9600);
}

void movexy(long x, long y) {
  if ((x >= 0 && x < 2000) && (y >= 0 && y < 2000)) {
    xMotor.moveTo(x);
    yMotor.moveTo(y);

    while (xMotor.distanceToGo() != 0 ||
           yMotor.distanceToGo() != 0) {

      xMotor.run();
      yMotor.run();
    }
  }
  else {
    Serial.println("Invalid Position !!");
  }
}

void loop() {

  Serial.println("Moving to Pick Position...");
  movexy(500, 300);
  delay(800);

  Serial.println("Picking...");
  delay(200);

  Serial.println("Moving to Place Position...");
  movexy(1200, 800);
  delay(800);

  Serial.println("Placing...");
  delay(200);

  Serial.println("Moving to Pick Position...");
  movexy(800, 200);
  delay(800);

  Serial.println("Picking...");
  delay(200);

  Serial.println("Moving to Place Position...");
  movexy(300, 1200);
  delay(800);

  Serial.println("Placing...");
  delay(200);

  Serial.println("Returning Home...");
  movexy(0, 0);
  delay(1000);
}
