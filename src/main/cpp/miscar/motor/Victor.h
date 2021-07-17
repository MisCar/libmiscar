#pragma once

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "miscar/motor/Motor.h"

namespace miscar {

class Victor : public Motor,
               public ctre::phoenix::motorcontrol::can::VictorSPX {
  Victor(int id);

  double GetPercentOutput() override;
  double GetPosition() override;
  double GetVelocity() override;

  void SetOutput(double output, Mode mode) override;
  void SetPID(PID pid) override;
  void SetCurrentLimit(ampere_t limit) override;
  void SetPosition(double position) override;
  void Brake() override;
  void Coast() override;
};

}  // namespace miscar