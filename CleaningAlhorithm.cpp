
#include "CleaningAlhorithm.h"


CleaningAlhorithm::CleaningAlhorithm (const Chassis& _chassis) : chassis(_chassis) {};

void CleaningAlhorithm::cleanForward(int forwardMovingTime) {
  chassis.moveForward();
  delay(forwardMovingTime);
  chassis.stopMoving();
  delay(WAIT_TIME);
}

void CleaningAlhorithm::turnAround180Left() {
  chassis.turnAround180Left();
  delay(WAIT_TIME);
}

void CleaningAlhorithm::turnAround180Right() {
  chassis.turnAround180Right();
  delay(WAIT_TIME);
}

void CleaningAlhorithm::snake(int forwardMovingTime) {
  cleanForward(forwardMovingTime);
  turnAround180Left();
  
  cleanForward(forwardMovingTime);
  turnAround180Right();
  
  chassis.stopMoving();
}
