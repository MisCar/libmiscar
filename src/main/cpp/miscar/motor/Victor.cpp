// Copyright (c) MisCar 1574

#include "miscar/motor/Victor.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr auto VICTOR_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Victor::Victor(std::string&& name, int id, int encoder_resolution)
    : BaseMotorController(id, "Victor SRX"),
      Motor(std::move(name), id, encoder_resolution),
      VictorSPX(id) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::VICTOR) {
    log::Warning(GetName() + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::VICTOR) + " is available.");
  }
}

double miscar::Victor::GetPercentOutput() { return GetMotorOutputPercent(); }

double miscar::Victor::GetPosition() {
  return GetSelectedSensorPosition() / GetEncoderResolution();
}

double miscar::Victor::GetVelocity() {
  return GetSelectedSensorVelocity() / GetEncoderResolution() /
         VICTOR_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value();
}

void miscar::Victor::SetOutput(double output, Mode mode) {
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

void miscar::Victor::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Victor::SetCurrentLimit(units::ampere_t limit) {
  log::Error("Victor SPX controllers do not support a current limit!");
}

void miscar::Victor::SetPosition(double position) {
  SetSelectedSensorPosition(position);
}

void miscar::Victor::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Victor::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
