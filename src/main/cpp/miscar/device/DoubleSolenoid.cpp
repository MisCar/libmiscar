// Copyright (c) MisCar 1574

#include "miscar/device/DoubleSolenoid.h"

#include <utility>

#include <frc/PneumaticsBase.h>
#include <frc/PneumaticsModuleType.h>

#include "miscar/device/Solenoid.h"

miscar::DoubleSolenoid::DoubleSolenoid(std::string name, int forward,
                                       int reverse)
    : miscar::Solenoid(name),
      m_solenoid(frc::PneumaticsModuleType::CTREPCM, forward, reverse) {}

bool miscar::DoubleSolenoid::Get() {
  return m_solenoid.Get() == frc::DoubleSolenoid::Value::kForward;
}

void miscar::DoubleSolenoid::Set(bool value) {
  m_solenoid.Set(value ? frc::DoubleSolenoid::Value::kForward
                       : frc::DoubleSolenoid::Value::kReverse);
}

miscar::DoubleSolenoid::operator frc::DoubleSolenoid&() { return m_solenoid; }
