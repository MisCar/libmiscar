// Copyright (c) MisCar 1574

#include "miscar/motor/Talon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

using namespace miscar;
using namespace units;

Talon::Talon(const std::string& name, int id)
    : BaseMotorController(id, "Talon SRX"),
      BaseTalon(id, "Talon SRX"),
      TalonSRX(id),
      Motor(name, id) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::TALON) {
    log::Warning(GetName() +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::TALON) + " is available.");
  }
}

double Talon::GetPercentOutput() { return GetMotorOutputPercent(); }

double Talon::GetPosition() { return GetSelectedSensorPosition(); }

double Talon::GetVelocity() { return GetSelectedSensorVelocity(); }

void Talon::SetOutput(double output, Mode mode) {
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

void Talon::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Talon::SetCurrentLimit(ampere_t limit) {
  ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void Talon::SetPosition(double position) {
  SetSelectedSensorPosition(position);
}

void Talon::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Talon::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
