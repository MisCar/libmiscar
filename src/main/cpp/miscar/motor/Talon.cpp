// Copyright (c) MisCar 1574

#include "miscar/motor/Talon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"
#include <units/time.h>

constexpr auto TALON_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Talon::Talon(std::string&& name, int id, int encoder_resolution)
    : BaseMotorController(id, "Talon SRX"),
      BaseTalon(id, "Talon SRX"),
      Motor(std::move(name), id, encoder_resolution),
      TalonSRX(id) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::TALON) {
    log::Warning(GetName() +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::TALON) + " is available.");
  }
}

double miscar::Talon::GetPercentOutput() { return GetMotorOutputPercent(); }

double miscar::Talon::GetPosition() {
  return GetSelectedSensorPosition() / GetEncoderResolution();
}

double miscar::Talon::GetVelocity() {
  return GetSelectedSensorVelocity() / GetEncoderResolution() /
         TALON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().to<double>();
}

void miscar::Talon::SetOutput(double output, Mode mode) {
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

void miscar::Talon::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Talon::SetCurrentLimit(units::ampere_t limit) {
  ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void miscar::Talon::SetPosition(double position) {
  SetSelectedSensorPosition(position);
}

void miscar::Talon::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Talon::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}
