
#include "Wheel.h"
#include "Chassis.h"
#include "CleaningAlhorithm.h"

const WheelPins LEFT_WHEEL_PINS = {2, 3, A0};
const WheelPins RIGHT_WHEEL_PINS = {4, 5, A1};

Wheel leftWheel ((WheelPins){2, 3, A0});
Wheel rightWheel ((WheelPins){4, 5, A1});
Chassis chassis (leftWheel, rightWheel);
CleaningAlhorithm cleaning (chassis);
void setup() {
  pinMode(leftWheel.pins.plus, OUTPUT);
  pinMode(leftWheel.pins.minus, OUTPUT);
  pinMode(rightWheel.pins.plus, OUTPUT);
  pinMode(rightWheel.pins.minus, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  
  cleaning.snake();
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}

