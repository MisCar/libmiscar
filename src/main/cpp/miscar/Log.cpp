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

void miscar::log::Network(const std::string& path, const std::string& message) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetString(message);
}

void miscar::log::Network(const std::string& path, bool value) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetBoolean(value);
}

void miscar::log::Network(const std::string& path, double value) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetDouble(value);
}
