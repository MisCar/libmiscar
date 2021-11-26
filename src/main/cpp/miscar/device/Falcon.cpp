// Copyright (c) MisCar 1574

#include "miscar/device/Falcon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <ctre/phoenix/motorcontrol/can/BaseMotorController.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr int FALCON_ENCODER_RESOLUTION = 2048;
constexpr auto FALCON_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Falcon::Falcon(std::string&& name, int id)
    : BaseMotorController(id, "Talon FX"),
      BaseTalon(id, "Talon FX"),
      Motor(std::move(name), id, FALCON_ENCODER_RESOLUTION),
      TalonFX(id) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::FALCON) {
    log::Warning(std::string(GetName()) + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::FALCON) + " is available.");
  }

  ConfigFactoryDefault();
  SetInverted(false);
}

double miscar::Falcon::GetPercentOutput() { return GetMotorOutputPercent(); }

double miscar::Falcon::GetPosition() {
  return GetSelectedSensorPosition() / FALCON_ENCODER_RESOLUTION;
}

double miscar::Falcon::GetVelocity() {
  return GetSelectedSensorVelocity() / FALCON_ENCODER_RESOLUTION /
         FALCON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value();
}

void miscar::Falcon::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, output);
      break;
    case Position:
      Set(ctre::phoenix::motorcontrol::ControlMode::Position,
          output * FALCON_ENCODER_RESOLUTION);
      break;
    case Velocity:
      Set(ctre::phoenix::motorcontrol::ControlMode::Velocity,
          output * FALCON_ENCODER_RESOLUTION *
              FALCON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value());
      break;
  }
}

void miscar::Falcon::SetPID(PID pid) {
  Config_kP(pid.slot, pid.p);
  Config_kI(pid.slot, pid.i);
  Config_kD(pid.slot, pid.d);
  Config_kF(pid.slot, pid.f);
  Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Falcon::SetCurrentLimit(units::ampere_t limit) {
  ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void miscar::Falcon::SetPosition(double position) {
  SetSelectedSensorPosition(position / FALCON_ENCODER_RESOLUTION);
}

void miscar::Falcon::Brake() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Falcon::Coast() {
  SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void miscar::Falcon::Invert() { SetInverted(!GetInverted()); }
