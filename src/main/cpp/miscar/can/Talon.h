// Copyright (c) MisCar 1574

#pragma once

#include <string>

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

#include "miscar/motor/Motor.h"

namespace miscar {

/**
 * AKA CTRE Talon SRX.
 * https://www.ctr-electronics.com/talon-srx.html
 */
class Talon : public Motor {
 public:
  Talon(std::string name, int id, int encoder_resolution);

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
  void Follow(Talon& talon);

  explicit operator ctre::phoenix::motorcontrol::can::TalonSRX&();

 private:
  ctre::phoenix::motorcontrol::can::TalonSRX m_talon;
};

}  // namespace miscar
