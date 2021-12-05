// Copyright (c) MisCar 1574

#include "miscar/Log.h"

#include <networktables/NetworkTableInstance.h>

#include <frc/Errors.h>

void miscar::log::Warning(const std::string& message) {
  FRC_ReportError(frc::err::Error, "[MisCar] {}", message);
}

void miscar::log::Error(const std::string& message) {
  FRC_ReportError(frc::warn::Warning, "[MisCar] {}", message);
}
