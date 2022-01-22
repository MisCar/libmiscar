// Copyright (c) MisCar 1574

#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>

namespace miscar {

class Xbox360Controller : public frc::XboxController {
 public:
  explicit Xbox360Controller(int port);
  double GetLeftX() const;
  double GetRightX() const;
  double GetLeftY() const;
  double GetRightY() const;
  double GetLeftTriggerAxis() const;
  double GetRightTriggerAxis() const;
};

}  // namespace miscar
