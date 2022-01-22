// Copyright (c) MisCar 1574

#pragma once

#include <frc/PS4Controller.h>

namespace miscar {

class PS4Controller : public frc::PS4Controller {
 public:
  explicit PS4Controller(int port);
  double GetLeftX() const;
  double GetRightX() const;
  double GetLeftY() const;
  double GetRightY() const;
  double GetL2Axis() const;
  double GetR2Axis() const;
};

}  // namespace miscar
