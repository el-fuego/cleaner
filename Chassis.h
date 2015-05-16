
#ifndef Chassis_h
#define Chassis_h
#include "Wheel.h"

class Chassis {
  private:
    Wheel rightWheel, leftWheel;
  
  public:
    Chassis (const Wheel& _leftWheel, const Wheel& _rightWheel);
  
    void moveForward();
    
    void moveBackward();
    
    void stopMoving();
    
    void turnLeft(boolean isAroundWheel = true);
    
    void turnRight(boolean isAroundWheel = true);
    
    void turnAround180Left();
    
    void turnAround180Right();
};

#endif
