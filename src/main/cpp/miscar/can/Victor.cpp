// Copyright (c) MisCar 1574

#include "miscar/can/Victor.h"

#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr auto VICTOR_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Victor::Victor(std::string name, int id, int encoder_resolution)
    : Motor(name, id, encoder_resolution), m_victor(id) {
  const int current_firmware = m_victor.GetFirmwareVersion();
  if (current_firmware != firmware::VICTOR) {
    log::Warning(std::string(GetName()) + " has outdated firmware: " +
                 std::to_string(current_firmware) + " when " +
                 std::to_string(firmware::VICTOR) + " is available.");
  }

  m_victor.ConfigFactoryDefault();
  m_victor.SetInverted(false);
}

double miscar::Victor::GetPercentOutput() {
  return m_victor.GetMotorOutputPercent();
}

double miscar::Victor::GetPosition() {
  return m_victor.GetSelectedSensorPosition() / GetEncoderResolution();
}

double miscar::Victor::GetVelocity() {
  return m_victor.GetSelectedSensorVelocity() / GetEncoderResolution() /
         VICTOR_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value();
}

void miscar::Victor::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      m_victor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
                   output);
      break;
    case Position:
      m_victor.Set(ctre::phoenix::motorcontrol::ControlMode::Position,
                   output * GetEncoderResolution());
      break;
    case Velocity:
      m_victor.Set(
          ctre::phoenix::motorcontrol::ControlMode::Velocity,
          output * GetEncoderResolution() *
              VICTOR_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value());
      break;
  }
}

void miscar::Victor::SetPID(PID pid) {
  m_victor.Config_kP(pid.slot, pid.p);
  m_victor.Config_kI(pid.slot, pid.i);
  m_victor.Config_kD(pid.slot, pid.d);
  m_victor.Config_kF(pid.slot, pid.f);
  m_victor.Config_IntegralZone(pid.slot, pid.integral_zone);
}

void miscar::Victor::SetCurrentLimit(units::ampere_t limit) {
  log::Error("Victor SPX controllers do not support a current limit!");
}

void miscar::Victor::SetPosition(double position) {
  m_victor.SetSelectedSensorPosition(position * GetEncoderResolution());
}

void miscar::Victor::Brake() {
  m_victor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void miscar::Victor::Coast() {
  m_victor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void miscar::Victor::Invert() { m_victor.SetInverted(true); }

miscar::Victor::operator ctre::phoenix::motorcontrol::can::VictorSPX &() {
  return GetBaseVictor();
}

ctre::phoenix::motorcontrol::can::VictorSPX &miscar::Victor::GetBaseVictor() {
  return m_victor;
}

void miscar::Victor::Follow(miscar::Victor &victor) {
  auto &other_victor =
      static_cast<ctre::phoenix::motorcontrol::can::VictorSPX &>(victor);
  m_victor.Follow(other_victor);
}
