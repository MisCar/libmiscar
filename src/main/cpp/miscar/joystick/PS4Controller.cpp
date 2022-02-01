// Copyright (c) MisCar 1574

#include "miscar/joystick/PS4Controller.h"

#include <hal/FRCUsageReporting.h>

miscar::PS4Controller::PS4Controller(int port) : GenericHID(port) {
  HAL_Report(HALUsageReporting::kResourceType_PS4Controller, port + 1);
}

double miscar::PS4Controller::GetLeftX() const {
  return GetRawAxis(Axis::kLeftX);
}

double miscar::PS4Controller::GetRightX() const {
  return GetRawAxis(Axis::kRightX);
}

double miscar::PS4Controller::GetLeftY() const {
  return -GetRawAxis(Axis::kLeftY);
}

double miscar::PS4Controller::GetRightY() const {
  return -GetRawAxis(Axis::kRightY);
}

double miscar::PS4Controller::GetL2Axis() const {
  return GetRawAxis(Axis::kL2);
}

double miscar::PS4Controller::GetR2Axis() const {
  return GetRawAxis(Axis::kR2);
}

bool miscar::PS4Controller::GetSquareButton() const {
  return GetRawButton(Button::kSquare);
}

bool miscar::PS4Controller::GetSquareButtonPressed() {
  return GetRawButtonPressed(Button::kSquare);
}

bool miscar::PS4Controller::GetSquareButtonReleased() {
  return GetRawButtonReleased(Button::kSquare);
}

bool miscar::PS4Controller::GetCrossButton() const {
  return GetRawButton(Button::kCross);
}

bool miscar::PS4Controller::GetCrossButtonPressed() {
  return GetRawButtonPressed(Button::kCross);
}

bool miscar::PS4Controller::GetCrossButtonReleased() {
  return GetRawButtonReleased(Button::kCross);
}

bool miscar::PS4Controller::GetCircleButton() const {
  return GetRawButton(Button::kCircle);
}

bool miscar::PS4Controller::GetCircleButtonPressed() {
  return GetRawButtonPressed(Button::kCircle);
}

bool miscar::PS4Controller::GetCircleButtonReleased() {
  return GetRawButtonReleased(Button::kCircle);
}

bool miscar::PS4Controller::GetTriangleButton() const {
  return GetRawButton(Button::kTriangle);
}

bool miscar::PS4Controller::GetTriangleButtonPressed() {
  return GetRawButtonPressed(Button::kTriangle);
}

bool miscar::PS4Controller::GetTriangleButtonReleased() {
  return GetRawButtonReleased(Button::kTriangle);
}

bool miscar::PS4Controller::GetL1Button() const {
  return GetRawButton(Button::kL1);
}

bool miscar::PS4Controller::GetL1ButtonPressed() {
  return GetRawButtonPressed(Button::kL1);
}

bool miscar::PS4Controller::GetL1ButtonReleased() {
  return GetRawButtonReleased(Button::kL1);
}

bool miscar::PS4Controller::GetR1Button() const {
  return GetRawButton(Button::kR1);
}

bool miscar::PS4Controller::GetR1ButtonPressed() {
  return GetRawButtonPressed(Button::kR1);
}

bool miscar::PS4Controller::GetR1ButtonReleased() {
  return GetRawButtonReleased(Button::kR1);
}

bool miscar::PS4Controller::GetShareButton() const {
  return GetRawButton(Button::kShare);
}

bool miscar::PS4Controller::GetShareButtonPressed() {
  return GetRawButtonPressed(Button::kShare);
}

bool miscar::PS4Controller::GetShareButtonReleased() {
  return GetRawButtonReleased(Button::kShare);
}

bool miscar::PS4Controller::GetOptionsButton() const {
  return GetRawButton(Button::kOptions);
}

bool miscar::PS4Controller::GetOptionsButtonPressed() {
  return GetRawButtonPressed(Button::kOptions);
}

bool miscar::PS4Controller::GetOptionsButtonReleased() {
  return GetRawButtonReleased(Button::kOptions);
}

bool miscar::PS4Controller::GetL3Button() const {
  return GetRawButton(Button::kL3);
}

bool miscar::PS4Controller::GetL3ButtonPressed() {
  return GetRawButtonPressed(Button::kL3);
}

bool miscar::PS4Controller::GetL3ButtonReleased() {
  return GetRawButtonReleased(Button::kL3);
}

bool miscar::PS4Controller::GetR3Button() const {
  return GetRawButton(Button::kR3);
}

bool miscar::PS4Controller::GetR3ButtonPressed() {
  return GetRawButtonPressed(Button::kR3);
}

bool miscar::PS4Controller::GetR3ButtonReleased() {
  return GetRawButtonReleased(Button::kR3);
}
