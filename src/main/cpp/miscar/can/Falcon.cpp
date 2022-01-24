// Copyright (c) MisCar 1574

#include "miscar/can/Falcon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <ctre/phoenix/motorcontrol/can/BaseMotorController.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"
#include "miscar/motor/Motor.h"

constexpr int FALCON_ENCODER_RESOLUTION = 2048;
constexpr auto FALCON_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Falcon::Falcon(std::string name, int id)
    : Motor(name, id, FALCON_ENCODER_RESOLUTION), m_falcon(id) {
  const int current_firmware = m_falcon.GetFirmwareVersion();
  if (current_firmware != firmware::FALCON) {
    log::Warning(std::string(GetName()) + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::FALCON) + " is available.");
  }

  m_falcon.ConfigFactoryDefault();
  m_falcon.SetInverted(false);
}

double miscar::Falcon::GetPercentOutput() {
  return m_falcon.GetMotorOutputPercent();
}

double miscar::Falcon::GetPosition() {
  return m_falcon.GetSelectedSensorPosition() / FALCON_ENCODER_RESOLUTION;
}

double miscar::Falcon::GetVelocity() {
  return m_falcon.GetSelectedSensorVelocity() / FALCON_ENCODER_RESOLUTION /
         FALCON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value() / 60;
}

void miscar::Falcon::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      m_falcon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                   output);
      break;
    case Position:
      m_falcon.Set(ctre::phoenix::motorcontrol::ControlMode::Position,
                   output * FALCON_ENCODER_RESOLUTION);
      break;
    case Velocity:
      m_falcon.Set(
          ctre::phoenix::motorcontrol::ControlMode::Velocity,
          output * FALCON_ENCODER_RESOLUTION *
              FALCON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value());
      break;
  }
}

void miscar::Falcon::SetPID(PID pid) {
  m_falcon.Config_kP(pid.slot, pid.p);
  m_falcon.Config_kI(pid.slot, pid.i);
  m_falcon.Config_kD(pid.slot, pid.d);
  m_falcon.Config_kF(pid.slot, pid.f);
  m_falcon.Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Falcon::SetCurrentLimit(units::ampere_t limit) {
  m_falcon.ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void miscar::Falcon::SetPosition(double position) {
  m_falcon.SetSelectedSensorPosition(position / FALCON_ENCODER_RESOLUTION);
}

void miscar::Falcon::Brake() {
  m_falcon.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Falcon::Coast() {
  m_falcon.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void miscar::Falcon::Invert() { m_falcon.SetInverted(true); }

ctre::phoenix::motorcontrol::can::TalonFX &miscar::Falcon::GetBaseFalcon() {
  return m_falcon;
}

miscar::Falcon::operator ctre::phoenix::motorcontrol::can::TalonFX &() {
  return GetBaseFalcon();
}

void miscar::Falcon::Follow(miscar::Falcon &falcon) {
  auto &other_falcon =
      static_cast<ctre::phoenix::motorcontrol::can::TalonFX &>(falcon);
  m_falcon.Follow(other_falcon);
}
