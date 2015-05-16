
#include "Wheel.h"
#include "Chassis.h"
#include "CleaningAlhorithm.h"
#include "IRRemoteControl.h"

const WheelPins LEFT_WHEEL_PINS = {2, 3, A0};
const WheelPins RIGHT_WHEEL_PINS = {4, 5, A1};
const int IR_REMOTE_PIN = 6;
const unsigned short IR_CONTROL_HEADER = 0b1000000001111111;

Wheel leftWheel ((WheelPins){2, 3, A0});
Wheel rightWheel ((WheelPins){4, 5, A1});
Chassis chassis (leftWheel, rightWheel);
CleaningAlhorithm cleaning (chassis);
IRRemoteControl console(IR_REMOTE_PIN, IR_CONTROL_HEADER);

void setup() {
  pinMode(leftWheel.pins.plus, OUTPUT);
  pinMode(leftWheel.pins.minus, OUTPUT);
  pinMode(rightWheel.pins.plus, OUTPUT);
  pinMode(rightWheel.pins.minus, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IR_REMOTE_PIN, INPUT);
}

void loop() {
  switch(console.readCommand()) {
    case 45390: 
      digitalWrite(LED_BUILTIN, HIGH);
      chassis.moveForward();
      break;
    case 54315: 
      digitalWrite(LED_BUILTIN, HIGH);
      chassis.moveBackward();
      break;
    case 37230:
      digitalWrite(LED_BUILTIN, HIGH);
      chassis.turnLeft();
      break;
    case 57630:
      digitalWrite(LED_BUILTIN, HIGH);
      chassis.turnRight();
      break;
    case 33150:
      chassis.stopMoving();
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 41310:
      digitalWrite(LED_BUILTIN, HIGH);
      cleaning.snake();
      digitalWrite(LED_BUILTIN, LOW);
      delay(5000);
      break;
    // 46155 - 1
    // 52275 - 2
    // 55335 - 3
    // 39015 - 4
    // 35955 - 5
    // 48450 - 6
    // 34935 - 7
    // 40035 - 8
    // 44370 - 9
    // 42330 - 0
  }
}

