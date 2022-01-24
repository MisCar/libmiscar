// Copyright (c) MisCar 1574

#pragma once

#include <string>
#include <vector>

#include <frc/Solenoid.h>

#include "miscar/device/Solenoid.h"

namespace miscar {

/** A pneumatic solenoid */
class SingleSolenoid : public frc::Solenoid, public miscar::Solenoid {
 public:
  explicit SingleSolenoid(std::string name, int port);

  bool Get() override;
  void Set(bool value) override;
};

}  // namespace miscar
