// Copyright (c) MisCar 1574

#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>

namespace miscar {

class Xbox360Controller : public frc::XboxController {
 public:
  explicit Xbox360Controller(int port);
};

}  // namespace miscar
