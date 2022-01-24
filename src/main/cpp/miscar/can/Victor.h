// Copyright (c) MisCar 1574

#pragma once

#include <string>

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "miscar/motor/Motor.h"

namespace miscar {

/**
 * AKA CTRE Victor SPX.
 * http://www.ctr-electronics.com/victor-spx.html
 */
class Victor : public Motor {
 public:
  Victor(std::string name, int id, int encoder_resolution);

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
  void Follow(Victor& victor);

  explicit operator ctre::phoenix::motorcontrol::can::VictorSPX&();

  ctre::phoenix::motorcontrol::can::VictorSPX& GetBaseVictor();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_victor;
};

}  // namespace miscar
