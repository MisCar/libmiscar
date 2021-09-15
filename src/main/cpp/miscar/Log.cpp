// Copyright (c) MisCar 1574

#include "miscar/Log.h"

#include <frc/DriverStation.h>
#include <networktables/NetworkTableInstance.h>

void miscar::log::Warning(const std::string& message) {
  frc::DriverStation::GetInstance().ReportWarning("[MisCar]   " + message);
}

void miscar::log::Error(const std::string& message) {
  frc::DriverStation::GetInstance().ReportError("[MisCar]   " + message);
}
