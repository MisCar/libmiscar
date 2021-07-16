#include "miscar/motor/Victor.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

#include "miscar/Log.h"

using namespace miscar;

Victor::Victor(int id) : BaseMotorController(id, "Victor SRX"), VictorSPX(id) {}

double Victor::GetPercentOutput() { return VictorSPX::GetMotorOutputPercent(); }

double Victor::GetPosition() { return VictorSPX::GetSelectedSensorPosition(); }

double Victor::GetVelocity() { return VictorSPX::GetSelectedSensorVelocity(); }

void Victor::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      VictorSPX::Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                     output);
      break;
    case Position:
      VictorSPX::Set(ctre::phoenix::motorcontrol::ControlMode::Position,
                     output);
      break;
    case Velocity:
      VictorSPX::Set(ctre::phoenix::motorcontrol::ControlMode::Velocity,
                     output);
      break;
  }
}

void Victor::SetPID(PID pid) {
  VictorSPX::Config_kP(pid.slot, pid.p);
  VictorSPX::Config_kI(pid.slot, pid.i);
  VictorSPX::Config_kD(pid.slot, pid.d);
  VictorSPX::Config_kF(pid.slot, pid.f);
  VictorSPX::Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Victor::SetCurrentLimit(ampere_t limit) {
  log::Error("Victor SPX cannot have a current limit!");
}

void Victor::SetPosition(double position) {
  VictorSPX::SetSelectedSensorPosition(position);
}

void Victor::Brake() {
  VictorSPX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Victor::Coast() {
  VictorSPX::SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}