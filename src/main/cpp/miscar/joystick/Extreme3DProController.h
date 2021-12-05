// Copyright (c) MisCar 1574

#pragma once

#include <frc/GenericHID.h>
#include <frc/Joystick.h>

namespace miscar {

class Extreme3DProController : public frc::GenericHID {
 public:
  explicit Extreme3DProController(int port);

  double GetX() const;
  double GetY() const;
  double GetSlider() const;
  double GetRotation() const;
};

}  // namespace miscar
