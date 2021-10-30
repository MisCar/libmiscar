// Copyright (c) MisCar 1574

#include "Network.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTableInstance.h>

#include <string>

#define TABLE_PREFIX "/MisCar/"

template <>
bool miscar::network::Get(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetBoolean(false);
}

template <>
int miscar::network::Get(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetDouble(0);
}

template <>
double miscar::network::Get(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetDouble(0);
}

template <>
std::string miscar::network::Get(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .GetString("");
}

template <>
std::vector<bool> miscar::network::Get(const std::string &path) {
  auto result = nt::NetworkTableInstance::GetDefault()
                    .GetEntry(TABLE_PREFIX + path)
                    .GetBooleanArray({});

  return std::vector<bool>(result.begin(), result.end());
}

template <>
std::vector<int> miscar::network::Get(const std::string &path) {
  auto result = nt::NetworkTableInstance::GetDefault()
                    .GetEntry(TABLE_PREFIX + path)
                    .GetDoubleArray({});

  return std::vector<int>(result.begin(), result.end());
}

template <>
void miscar::network::Set(const std::string &path, bool value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetBoolean(value);
}

template <>
void miscar::network::Set(const std::string &path, int value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDouble(value);
}

template <>
void miscar::network::Set(const std::string &path, double value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDouble(value);
}

template <>
void miscar::network::Set(const std::string &path, std::string value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetString(value);
}

template <>
void miscar::network::Set(const std::string &path, std::vector<bool> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetBooleanArray(std::vector<int>(value.begin(), value.end()));
}

template <>
void miscar::network::Set(const std::string &path, std::vector<int> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDoubleArray(std::vector<double>(value.begin(), value.end()));
}

template <>
void miscar::network::Set(const std::string &path, std::vector<double> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDoubleArray(value);
}

template <>
void miscar::network::Set(const std::string &path,
                          std::vector<std::string> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetStringArray(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, bool value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultBoolean(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, int value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultDouble(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, double value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultDouble(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, std::string value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultString(value);
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<bool> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultBooleanArray(std::vector<int>(value.begin(), value.end()));
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<int> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultDoubleArray(std::vector<double>(value.begin(), value.end()));
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<double> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultDoubleArray(value);
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<std::string> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(TABLE_PREFIX + path)
      .SetDefaultStringArray(value);
}

void miscar::network::Add(const std::string &path, frc::Sendable &sendable) {
  frc::SmartDashboard::PutData(path, &sendable);
}
