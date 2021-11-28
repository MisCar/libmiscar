// Copyright (c) MisCar 1574

#include "miscar/device/Talon.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr auto TALON_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Talon::Talon(std::string&& name, int id, int encoder_resolution)
    : Motor(std::move(name), id, encoder_resolution), m_talon(id) {
  const int current_firmware = m_talon.GetFirmwareVersion();
  if (current_firmware != firmware::TALON) {
    log::Warning(std::string(GetName()) +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::TALON) + " is available.");
  }

  m_talon.ConfigFactoryDefault();
  m_talon.SetInverted(false);
}

double miscar::Talon::GetPercentOutput() {
  return m_talon.GetMotorOutputPercent();
}

double miscar::Talon::GetPosition() {
  return m_talon.GetSelectedSensorPosition() / GetEncoderResolution();
}

double miscar::Talon::GetVelocity() {
  return m_talon.GetSelectedSensorVelocity() / GetEncoderResolution() /
         TALON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value();
}

void miscar::Talon::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      m_talon.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                  output);
      break;
    case Position:
      m_talon.Set(ctre::phoenix::motorcontrol::ControlMode::Position,
                  output * GetEncoderResolution());
      break;
    case Velocity:
      m_talon.Set(
          ctre::phoenix::motorcontrol::ControlMode::Velocity,
          output * GetEncoderResolution() *
              TALON_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value());
      break;
  }
}

void miscar::Talon::SetPID(PID pid) {
  m_talon.Config_kP(pid.slot, pid.p);
  m_talon.Config_kI(pid.slot, pid.i);
  m_talon.Config_kD(pid.slot, pid.d);
  m_talon.Config_kF(pid.slot, pid.f);
  m_talon.Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Talon::SetCurrentLimit(units::ampere_t limit) {
  m_talon.ConfigSupplyCurrentLimit(
      ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration(
          true, limit.value(), 0, 0));
}

void miscar::Talon::SetPosition(double position) {
  m_talon.SetSelectedSensorPosition(position / GetEncoderResolution());
}

void miscar::Talon::Brake() {
  m_talon.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Talon::Coast() {
  m_talon.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void miscar::Talon::Invert() { m_talon.SetInverted(!m_talon.GetInverted()); }

miscar::Talon::operator ctre::phoenix::motorcontrol::can::TalonSRX&() {
  return m_talon;
}
