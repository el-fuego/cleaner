
#ifndef CleaningAlhorithm_h
#define CleaningAlhorithm_h
#include "Chassis.h"

class CleaningAlhorithm {
  private:
    Chassis chassis;
    static const int WAIT_TIME = 100;
    
    void cleanForward(int forwardMovingTime);
    
    void turnAround180Left();
    
    void turnAround180Right();
  
  public:
    CleaningAlhorithm(const Chassis& _chassis);
    
    void snake(int forwardMovingTime = 2000);
};

#endif
