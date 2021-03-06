// Copyright (c) MisCar 1574

#pragma once

#include <string>

#include <frc/motorcontrol/Talon.h>

#include "miscar/motor/Motor.h"

namespace miscar::pwm {

class Talon : public Motor, public frc::Talon {
 public:
  explicit Talon(std::string name, int id);

  double GetPercentOutput() override;
  double GetPosition() override;
  double GetVelocity() override;

  void SetOutput(double output, Mode mode) override;
  void SetPID(PID pid) override;
  void SetCurrentLimit(units::ampere_t limit) override;
  void SetPosition(double position) override;
  void Brake() override;
  void Coast() override;
  void Invert() override;
};

}  // namespace miscar::pwm
