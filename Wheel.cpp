
#include "Wheel.h"

Wheel::Wheel (WheelPins _pins) {
  pins = _pins;
};
void Wheel::moveForward() {
  digitalWrite(pins.plus, HIGH);
  digitalWrite(pins.minus, LOW);
};
void Wheel::moveBackward() {
  digitalWrite(pins.plus, LOW);
  digitalWrite(pins.minus, HIGH);
};
void Wheel::stopMoving() {
  digitalWrite(pins.plus, LOW);
  digitalWrite(pins.minus, LOW);
};
