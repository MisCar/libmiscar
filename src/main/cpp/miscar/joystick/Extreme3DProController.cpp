// Copyright (c) MisCar 1574

#include "miscar/joystick/Extreme3DProController.h"

#include <frc/GenericHID.h>

miscar::Extreme3DProController::Extreme3DProController(int port)
    : frc::GenericHID(port) {}

double miscar::Extreme3DProController::GetX() const { return GetRawAxis(0); }

double miscar::Extreme3DProController::GetY() const { return -GetRawAxis(1); }

double miscar::Extreme3DProController::GetRotation() const {
  return GetRawAxis(2);
}

double miscar::Extreme3DProController::GetSlider() const {
  return -GetRawAxis(3);
}
