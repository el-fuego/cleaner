#include "IRBarrierSensor.h"

IRBarrierSensor barrierSensor({A3, 9});

void setup() {
  pinMode(barrierSensor.pins.led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, barrierSensor.hasBarrier() ? HIGH : LOW);
  
  if(barrierSensor.hasBarrier() ) {
    Serial.println('----------BARRIER----------');
  }
  delay(10);
}
