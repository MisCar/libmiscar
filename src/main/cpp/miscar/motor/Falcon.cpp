// Copyright (c) MisCar 1574

#include "miscar/motor/Falcon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

using namespace miscar;

constexpr int FALCON_ENCODER_RESOLUTION = 4096;

Falcon::Falcon(const std::string& name, int id)
    : BaseMotorController(id, "Talon FX"),
      BaseTalon(id, "Talon FX"),
      TalonFX(id),
      Motor(name, id, FALCON_ENCODER_RESOLUTION) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::FALCON) {
    log::Warning(GetName() + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::FALCON) + " is available.");
  }
}

double Falcon::GetPercentOutput() { return GetMotorOutputPercent(); }

double Falcon::GetPosition() { return GetSelectedSensorPosition(); }

double Falcon::GetVelocity() { return GetSelectedSensorVelocity(); }

void Falcon::SetOutput(double output, Mode mode) {
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

void Falcon::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void Falcon::SetCurrentLimit(units::ampere_t limit) {
  ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void Falcon::SetPosition(double position) {
  SetSelectedSensorPosition(position);
}

void Falcon::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void Falcon::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
