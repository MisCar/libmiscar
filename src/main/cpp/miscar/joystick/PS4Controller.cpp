// Copyright (c) MisCar 1574

#include "miscar/joystick/PS4Controller.h"

#include "miscar/Fix.h"

constexpr double FIX_RANGE = 0.1;

miscar::PS4Controller::PS4Controller(int port) : m_ps4(port) {}

double miscar::PS4Controller::GetLeftX() const {
  return miscar::Fix(m_ps4.GetLeftX(), FIX_RANGE);
}

double miscar::PS4Controller::GetRightX() const {
  return miscar::Fix(m_ps4.GetRightX(), FIX_RANGE);
}

double miscar::PS4Controller::GetLeftY() const {
  return miscar::Fix(m_ps4.GetLeftY(), FIX_RANGE);
}

double miscar::PS4Controller::GetRightY() const {
  return miscar::Fix(m_ps4.GetRightY(), FIX_RANGE);
}

double miscar::PS4Controller::GetL2Axis() const {
  return miscar::Fix(m_ps4.GetL2Axis(), FIX_RANGE);
}

double miscar::PS4Controller::GetR2Axis() const {
  return miscar::Fix(m_ps4.GetR2Axis(), FIX_RANGE);
}

bool miscar::PS4Controller::GetSquareButton() const {
  return m_ps4.GetSquareButton();
}

bool miscar::PS4Controller::GetSquareButtonPressed() {
  return m_ps4.GetSquareButtonPressed();
}

bool miscar::PS4Controller::GetSquareButtonReleased() {
  return m_ps4.GetSquareButtonReleased();
}

bool miscar::PS4Controller::GetCrossButton() const {
  return m_ps4.GetCrossButton();
}

bool miscar::PS4Controller::GetCrossButtonPressed() {
  return m_ps4.GetCrossButtonPressed();
}

bool miscar::PS4Controller::GetCrossButtonReleased() {
  return m_ps4.GetCrossButtonReleased();
}

bool miscar::PS4Controller::GetCircleButton() const {
  return m_ps4.GetCircleButton();
}

bool miscar::PS4Controller::GetCircleButtonPressed() {
  return m_ps4.GetCircleButtonPressed();
}

bool miscar::PS4Controller::GetCircleButtonReleased() {
  return m_ps4.GetCircleButtonReleased();
}

bool miscar::PS4Controller::GetTriangleButton() const {
  return m_ps4.GetTriangleButton();
}

bool miscar::PS4Controller::GetTriangleButtonPressed() {
  return m_ps4.GetTriangleButtonPressed();
}

bool miscar::PS4Controller::GetTriangleButtonReleased() {
  return m_ps4.GetTriangleButtonReleased();
}

bool miscar::PS4Controller::GetL1Button() const { return m_ps4.GetL1Button(); }

bool miscar::PS4Controller::GetL1ButtonPressed() {
  return m_ps4.GetL1ButtonPressed();
}

bool miscar::PS4Controller::GetL1ButtonReleased() {
  return m_ps4.GetL1ButtonReleased();
}

bool miscar::PS4Controller::GetR1Button() const { return m_ps4.GetR1Button(); }

bool miscar::PS4Controller::GetR1ButtonPressed() {
  return m_ps4.GetR1ButtonPressed();
}

bool miscar::PS4Controller::GetR1ButtonReleased() {
  return m_ps4.GetR1ButtonReleased();
}

bool miscar::PS4Controller::GetL2Button() const { return m_ps4.GetL2Button(); }

bool miscar::PS4Controller::GetL2ButtonPressed() {
  return m_ps4.GetL2ButtonPressed();
}

bool miscar::PS4Controller::GetL2ButtonReleased() {
  return m_ps4.GetL2ButtonReleased();
}

bool miscar::PS4Controller::GetR2Button() const { return m_ps4.GetR2Button(); }

bool miscar::PS4Controller::GetR2ButtonPressed() {
  return m_ps4.GetR2ButtonPressed();
}

bool miscar::PS4Controller::GetR2ButtonReleased() {
  return m_ps4.GetR2ButtonReleased();
}

bool miscar::PS4Controller::GetShareButton() const {
  return m_ps4.GetShareButton();
}

bool miscar::PS4Controller::GetShareButtonPressed() {
  return m_ps4.GetShareButtonPressed();
}

bool miscar::PS4Controller::GetShareButtonReleased() {
  return m_ps4.GetShareButtonReleased();
}

bool miscar::PS4Controller::GetOptionsButton() const {
  return m_ps4.GetOptionsButton();
}

bool miscar::PS4Controller::GetOptionsButtonPressed() {
  return m_ps4.GetOptionsButtonPressed();
}

bool miscar::PS4Controller::GetOptionsButtonReleased() {
  return m_ps4.GetOptionsButtonReleased();
}

bool miscar::PS4Controller::GetL3Button() const { return m_ps4.GetL3Button(); }

bool miscar::PS4Controller::GetL3ButtonPressed() {
  return m_ps4.GetL3ButtonPressed();
}

bool miscar::PS4Controller::GetL3ButtonReleased() {
  return m_ps4.GetL3ButtonReleased();
}

bool miscar::PS4Controller::GetR3Button() const { return m_ps4.GetR3Button(); }

bool miscar::PS4Controller::GetR3ButtonPressed() {
  return m_ps4.GetR3ButtonPressed();
}

bool miscar::PS4Controller::GetR3ButtonReleased() {
  return m_ps4.GetR3ButtonReleased();
}

bool miscar::PS4Controller::GetPSButton() const { return m_ps4.GetPSButton(); }

bool miscar::PS4Controller::GetPSButtonPressed() {
  return m_ps4.GetPSButtonPressed();
}

bool miscar::PS4Controller::GetPSButtonReleased() {
  return m_ps4.GetPSButtonReleased();
}

bool miscar::PS4Controller::GetTouchpad() const { return m_ps4.GetTouchpad(); }

bool miscar::PS4Controller::GetTouchpadPressed() {
  return m_ps4.GetTouchpadPressed();
}

bool miscar::PS4Controller::GetTouchpadReleased() {
  return m_ps4.GetTouchpadReleased();
}
