// Copyright (c) MisCar 1574

#include "miscar/joystick/PS4Controller.h"

#include "miscar/Fix.h"

constexpr double FIX_RANGE = 0.1;

miscar::PS4Controller::PS4Controller(int port) : frc::PS4Controller(port) {}

double miscar::PS4Controller::GetLeftX() const {
  return miscar::Fix(frc::PS4Controller::GetLeftX(), FIX_RANGE);
}

double miscar::PS4Controller::GetRightX() const {
  return miscar::Fix(frc::PS4Controller::GetRightX(), FIX_RANGE);
}

double miscar::PS4Controller::GetLeftY() const {
  return miscar::Fix(frc::PS4Controller::GetLeftY(), FIX_RANGE);
}

double miscar::PS4Controller::GetRightY() const {
  return miscar::Fix(frc::PS4Controller::GetRightY(), FIX_RANGE);
}

double miscar::PS4Controller::GetL2Axis() const {
  return miscar::Fix(frc::PS4Controller::GetL2Axis(), FIX_RANGE);
}

double miscar::PS4Controller::GetR2Axis() const {
  return miscar::Fix(frc::PS4Controller::GetR2Axis(), FIX_RANGE);
}
