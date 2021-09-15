// Copyright (c) MisCar 1574

#include "Network.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTableInstance.h>

#include <string>

#define TABLE_PREFIX "/MisCar/"

template <>
bool miscar::network::Get<bool>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetBoolean(false);
}

template <>
int miscar::network::Get<int>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetDouble(0);
}

template <>
double miscar::network::Get<double>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetDouble(0);
}

template <>
std::string miscar::network::Get<std::string>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetString("");
}

template <>
void miscar::network::Set<bool>(const std::string &path, bool value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetBoolean(value);
}

template <>
void miscar::network::Set<int>(const std::string &path, int value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDouble(value);
}

template <>
void miscar::network::Set<double>(const std::string &path, double value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDouble(value);
}

template <>
void miscar::network::Set<std::string>(const std::string &path,
                                       std::string value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetString(value);
}

void miscar::network::Add(const std::string &path, frc::Sendable &sendable) {
  frc::SmartDashboard::PutData(path, &sendable);
}
