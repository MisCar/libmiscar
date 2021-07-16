#include "miscar/Log.h"

#include <frc/DriverStation.h>
#include <networktables/NetworkTableInstance.h>

using namespace miscar;

void log::Warning(const std::string& message) {
  frc::DriverStation::GetInstance().ReportWarning("[MisCar]   " + message);
}

void log::Error(const std::string& message) {
  frc::DriverStation::GetInstance().ReportError("[MisCar]   " + message);
}

void log::Network(const std::string& path, const std::string& message) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetString(message);
}

void log::Network(const std::string& path, bool value) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetBoolean(value);
}

void log::Network(const std::string& path, double value) {
  nt::NetworkTableInstance::GetDefault().GetEntry(path).SetDouble(value);
}