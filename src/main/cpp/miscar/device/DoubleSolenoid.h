// Copyright (c) MisCar 1574

#pragma once

#include <string>
#include <vector>

#include <frc/DoubleSolenoid.h>

#include "miscar/device/Solenoid.h"

namespace miscar {

/** A pneumatic DoubleSolenoid */
class DoubleSolenoid : public Solenoid {
 public:
  explicit DoubleSolenoid(std::string name, int forward, int reverse);

  bool Get() override;
  void Set(bool value) override;

  explicit operator frc::DoubleSolenoid&();

 private:
  frc::DoubleSolenoid m_solenoid;
};

}  // namespace miscar
