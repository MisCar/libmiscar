// Copyright (c) MisCar 1574

#include "miscar/joystick/Extreme3DProController.h"

#include <frc/GenericHID.h>

#include "miscar/Fix.h"

constexpr double FIX_RANGE = 0.1;

miscar::Extreme3DProController::Extreme3DProController(int port)
    : frc::GenericHID(port) {}

double miscar::Extreme3DProController::GetX() const {
  return miscar::Fix(GetRawAxis(0), FIX_RANGE);
}

double miscar::Extreme3DProController::GetY() const {
  return miscar::Fix(-GetRawAxis(1), FIX_RANGE);
}

double miscar::Extreme3DProController::GetRotation() const {
  return miscar::Fix(GetRawAxis(2), FIX_RANGE);
}

double miscar::Extreme3DProController::GetSlider() const {
  return miscar::Fix(-GetRawAxis(3), FIX_RANGE);
}
