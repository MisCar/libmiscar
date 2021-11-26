// Copyright (c) MisCar 1574

#include "miscar/Log.h"

#include <networktables/NetworkTableInstance.h>

#include <frc/Errors.h>

void miscar::log::Warning(const std::string& message) {
  FRC_ReportError(1574, "[MisCar WARNING] {}", message);
}

void miscar::log::Error(const std::string& message) {
  FRC_ReportError(1574, "[MisCar ERROR] {}", message);
}
