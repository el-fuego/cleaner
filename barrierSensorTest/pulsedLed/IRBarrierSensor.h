
#ifndef IRBarrierSensor_h
#define IRBarrierSensor_h

class IRBarrierSensor {
  struct Pins {
    float sensor;
    float led;
  };
  struct SensorValues {
    float dark;
    float light;
  };
  private:
    unsigned long lastLedHighlightAt = 0;
    int measurementTime;
    float sensivityLevel, calibrationLevel;
    SensorValues defaultValues;
    
    // Sensor values with LED turned off and on
    SensorValues readValues();
    
    // Deviation of lightness to determine barrier
    float getDeviation(SensorValues values);
    
    // Is sensor already calibrated? For first run
    bool isCalibrated ();
    
    // Is need runtime calibration
    bool isNeedCalibration (SensorValues values);
    
    // Set defaultValues
    void calibrateSensor (SensorValues values);
  
  public:
    IRBarrierSensor(Pins _pins, float _sensivityLevel = 0.05, int _measurementTime = 10, float _calibrationLevel = 0.1);
    
    Pins pins;
    
    // Calibrate sensor to current lightness
    void calibrate ();
    
    // Deviation of lightness to determine barrier.
    // Calibrate sensors automatically if calibrationLevel between values with offed LED is reached
    float getRaw ();

    // Is barrier determined by sensivityLevel? Use getRaw()
    bool hasBarrier ();
};

#endif
