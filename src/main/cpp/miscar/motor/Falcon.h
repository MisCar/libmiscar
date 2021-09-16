// Copyright (c) MisCar 1574

#pragma once

#include <ctre/phoenix/motorcontrol/can/TalonFX.h>

#include <string>

#include "miscar/motor/Motor.h"

namespace miscar {

/**
 * AKA CTRE/VEX Talon FX.
 * https://www.ctr-electronics.com/talon-fx.html
 */
class Falcon : public Motor, public ctre::phoenix::motorcontrol::can::TalonFX {
 public:
  Falcon(std::string&& name, int id);

  double GetPercentOutput() override;
  double GetPosition() override;
  double GetVelocity() override;

  void SetOutput(double output, Mode mode) override;
  void SetPID(PID pid) override;
  void SetCurrentLimit(units::ampere_t limit) override;
  void SetPosition(double position) override;
  void Brake() override;
  void Coast() override;
};

}  // namespace miscar
