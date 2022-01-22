// Copyright (c) MisCar 1574

#include "miscar/joystick/Xbox360Controller.h"

#include "miscar/Fix.h"

constexpr double FIX_RANGE = 0.1;

miscar::Xbox360Controller::Xbox360Controller(int port)
    : frc::XboxController(port) {}

double miscar::Xbox360Controller::GetLeftX() const {
  return miscar::Fix(frc::XboxController::GetLeftX(), FIX_RANGE);
}

double miscar::Xbox360Controller::GetRightX() const {
  return miscar::Fix(frc::XboxController::GetRightX(), FIX_RANGE);
}

double miscar::Xbox360Controller::GetLeftY() const {
  return miscar::Fix(frc::XboxController::GetLeftY(), FIX_RANGE);
}

double miscar::Xbox360Controller::GetRightY() const {
  return miscar::Fix(frc::XboxController::GetRightY(), FIX_RANGE);
}

double miscar::Xbox360Controller::GetLeftTriggerAxis() const {
  return miscar::Fix(frc::XboxController::GetLeftTriggerAxis(), FIX_RANGE);
}

double miscar::Xbox360Controller::GetRightTriggerAxis() const {
  return miscar::Fix(frc::XboxController::GetRightTriggerAxis(), FIX_RANGE);
}
