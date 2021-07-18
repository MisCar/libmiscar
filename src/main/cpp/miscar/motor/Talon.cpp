// Copyright (c) MisCar 1574

#include "miscar/motor/Talon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

using namespace miscar;
using namespace units;

Talon::Talon(int id)
    : BaseMotorController(id, "Talon SRX"),
      BaseTalon(id, "Talon SRX"),
      TalonSRX(id) {}

double Talon::GetPercentOutput() { return TalonSRX::GetMotorOutputPercent(); }

double Talon::GetPosition() { return TalonSRX::GetSelectedSensorPosition(); }

double Talon::GetVelocity() { return TalonSRX::GetSelectedSensorVelocity(); }

void Talon::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      TalonSRX::Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                    output);
      break;
    case Position:
      TalonSRX::Set(ctre::phoenix::motorcontrol::ControlMode::Position, output);
      break;
    case Velocity:
      TalonSRX::Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, output);
      break;
  }
}

void Talon::SetPID(PID pid) {
  TalonSRX::Config_kP(pid.slot, pid.p);
  TalonSRX::Config_kI(pid.slot, pid.i);
  TalonSRX::Config_kD(pid.slot, pid.d);
  TalonSRX::Config_kF(pid.slot, pid.f);
  TalonSRX::Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Talon::SetCurrentLimit(ampere_t limit) {
  TalonSRX::ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void Talon::SetPosition(double position) {
  TalonSRX::SetSelectedSensorPosition(position);
}

void Talon::Brake() {
  TalonSRX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Talon::Coast() {
  TalonSRX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
