
#include "Chassis.h"

Chassis::Chassis(const Wheel& _leftWheel, const Wheel& _rightWheel) : leftWheel(_leftWheel), rightWheel(_rightWheel) {}

void Chassis::moveForward() {
  leftWheel.moveForward();
  rightWheel.moveForward();
}

void Chassis::stopMoving() {
  leftWheel.stopMoving();
  rightWheel.stopMoving();
}

void Chassis::turnLeft(boolean isAroundWheel) {
  rightWheel.moveForward();
  
  if (isAroundWheel) {
    leftWheel.stopMoving();
  } else {
    leftWheel.moveBackward();
  }
}

void Chassis::turnRight(boolean isAroundWheel) {
  leftWheel.moveForward();
  
  if (isAroundWheel) {  
    rightWheel.stopMoving();
  } else {
    rightWheel.moveBackward();
  }
}

void Chassis::turnAround180Left() {
  turnLeft();
  delay(950);
  stopMoving();
}

void Chassis::turnAround180Right() {
  turnRight();
  delay(1600);
  stopMoving();
}
