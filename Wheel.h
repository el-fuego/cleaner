
#ifndef Wheel_h
#define Wheel_h
#include "WheelPins.h"
#include "Arduino.h"

class Wheel {
  public: 
    Wheel(struct WheelPins);
    WheelPins pins;
    void moveForward();
    void moveBackward();
    void stopMoving();
};

#endif
