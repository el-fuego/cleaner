
#ifndef IRBarrierSensor_h
#define IRBarrierSensor_h
#include "Arduino.h"

// With LED always turned on
class IRBarrierSensor {
  private:
    unsigned long lastCalibrationTime = 0;
    float defaultValue;
    int sensorPin;
    
    void assideCalibration ();
    bool isNeedCalibration (bool hasBarrier);
  
  public:
    int calibrationTimeout;
    float barrierLimitDeviation;
    
    IRBarrierSensor(int _sensorPin, float _barrierLimitDeviation = 0.2, int _calibrationTimeout = 300);

    void calibrate ();

    bool hasBarrier ();
};

#endif
