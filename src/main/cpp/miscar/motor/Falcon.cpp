// Copyright (c) MisCar 1574

#include "miscar/motor/Falcon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

using namespace miscar;
using namespace units;

Falcon::Falcon(int id)
    : BaseMotorController(id, "Talon FX"),
      BaseTalon(id, "Talon FX"),
      TalonFX(id) {}

double Falcon::GetPercentOutput() { return TalonFX::GetMotorOutputPercent(); }

double Falcon::GetPosition() { return TalonFX::GetSelectedSensorPosition(); }

double Falcon::GetVelocity() { return TalonFX::GetSelectedSensorVelocity(); }

void Falcon::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      TalonFX::Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                   output);
      break;
    case Position:
      TalonFX::Set(ctre::phoenix::motorcontrol::ControlMode::Position, output);
      break;
    case Velocity:
      TalonFX::Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, output);
      break;
  }
}

void Falcon::SetPID(PID pid) {
  TalonFX::Config_kP(pid.slot, pid.p);
  TalonFX::Config_kI(pid.slot, pid.i);
  TalonFX::Config_kD(pid.slot, pid.d);
  TalonFX::Config_kF(pid.slot, pid.f);
  TalonFX::Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Falcon::SetCurrentLimit(ampere_t limit) {
  TalonFX::ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void Falcon::SetPosition(double position) {
  TalonFX::SetSelectedSensorPosition(position);
}

void Falcon::Brake() {
  TalonFX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Falcon::Coast() {
  TalonFX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
