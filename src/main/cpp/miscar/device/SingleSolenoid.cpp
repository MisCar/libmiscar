// Copyright (c) MisCar 1574

#include "miscar/device/SingleSolenoid.h"

#include <utility>

#include <frc/PneumaticsModuleType.h>

miscar::SingleSolenoid::SingleSolenoid(std::string name, int port)
    : frc::Solenoid(frc::PneumaticsModuleType::CTREPCM, port),
      miscar::Solenoid(name) {}

bool miscar::SingleSolenoid::Get() { return frc::Solenoid::Get(); }

void miscar::SingleSolenoid::Set(bool value) { frc::Solenoid::Set(value); }
