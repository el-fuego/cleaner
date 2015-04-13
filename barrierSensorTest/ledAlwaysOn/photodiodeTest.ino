#include "IRBarrierSensor.h"

int barrierSensorPin = A3;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

IRBarrierSensor barrierSensor(barrierSensorPin);

void loop() {
  
  digitalWrite(LED_BUILTIN, barrierSensor.hasBarrier() ? HIGH : LOW);
  
  delay(100);
}
