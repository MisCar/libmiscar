// Copyright (c) MisCar 1574

#include "miscar/motor/Victor.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

using namespace miscar;
using namespace units;

Victor::Victor(const std::string& name, int id, int encoder_resolution)
    : BaseMotorController(id, "Victor SRX"),
      Motor(name, id, encoder_resolution),
      VictorSPX(id) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::VICTOR) {
    log::Warning(GetName() + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::VICTOR) + " is available.");
  }
}

double Victor::GetPercentOutput() { return GetMotorOutputPercent(); }

double Victor::GetPosition() { return GetSelectedSensorPosition(); }

double Victor::GetVelocity() { return GetSelectedSensorVelocity(); }

void Victor::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
      break;
    case Position:
      Set(ctre::phoenix::motorcontrol::ControlMode::Position, output);
      break;
    case Velocity:
      Set(ctre::phoenix::motorcontrol::ControlMode::Velocity, output);
      break;
  }
}

void Victor::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Victor::SetCurrentLimit(ampere_t limit) {
  log::Error("Victor SPX controllers do not support a current limit!");
}

void Victor::SetPosition(double position) {
  SetSelectedSensorPosition(position);
}

void Victor::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Victor::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
