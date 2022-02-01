// Copyright (c) MisCar 1574

#pragma once

#include <frc/PS4Controller.h>

namespace miscar {

class PS4Controller {  //: public frc::PS4Controller {
 public:
  explicit PS4Controller(int port);
  double GetLeftX() const;
  double GetRightX() const;
  double GetLeftY() const;
  double GetRightY() const;
  double GetL2Axis() const;
  double GetR2Axis() const;

  bool GetSquareButton() const;
  bool GetSquareButtonPressed();
  bool GetSquareButtonReleased();

  bool GetCrossButton() const;
  bool GetCrossButtonPressed();
  bool GetCrossButtonReleased();

  bool GetCircleButton() const;
  bool GetCircleButtonPressed();
  bool GetCircleButtonReleased();

  bool GetTriangleButton() const;
  bool GetTriangleButtonPressed();
  bool GetTriangleButtonReleased();

  bool GetL1Button() const;
  bool GetL1ButtonPressed();
  bool GetL1ButtonReleased();

  bool GetR1Button() const;
  bool GetR1ButtonPressed();
  bool GetR1ButtonReleased();

  bool GetL2Button() const;
  bool GetL2ButtonPressed();
  bool GetL2ButtonReleased();

  bool GetR2Button() const;
  bool GetR2ButtonPressed();
  bool GetR2ButtonReleased();

  bool GetShareButton() const;
  bool GetShareButtonPressed();
  bool GetShareButtonReleased();

  bool GetOptionsButton() const;
  bool GetOptionsButtonPressed();
  bool GetOptionsButtonReleased();

  bool GetL3Button() const;
  bool GetL3ButtonPressed();
  bool GetL3ButtonReleased();

  bool GetR3Button() const;
  bool GetR3ButtonPressed();
  bool GetR3ButtonReleased();

  bool GetPSButton() const;
  bool GetPSButtonPressed();
  bool GetPSButtonReleased();

  bool GetTouchpad() const;
  bool GetTouchpadPressed();
  bool GetTouchpadReleased();

 private:
  frc::PS4Controller m_ps4;
};

}  // namespace miscar
