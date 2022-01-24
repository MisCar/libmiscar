// Copyright (c) MisCar 1574

#include "Network.h"

#include <networktables/NetworkTableInstance.h>

#include <string>
#include <vector>

#include <frc/smartdashboard/SmartDashboard.h>

#define TABLE_PREFIX "/MisCar/"

template <>
bool miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));
  auto value = entry.GetBoolean(false);
  entry.SetBoolean(value);
  return value;
}

template <>
int miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));
  auto value = entry.GetDouble(0);
  entry.SetDouble(value);
  return value;
}

template <>
double miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));
  auto value = entry.GetDouble(false);
  entry.SetDouble(value);
  return value;
}

template <>
std::string miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));

  auto value = entry.GetString("");
  entry.SetString(value);
  return value;
}

template <>
std::vector<bool> miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));

  auto value = entry.GetBooleanArray({});
  entry.SetBooleanArray(value);

  return std::vector<bool>(value.begin(), value.end());
}

template <>
std::vector<int> miscar::network::Get(const std::string &path) {
  auto entry = nt::NetworkTableInstance::GetDefault().GetEntry(Normalize(path));

  auto value = entry.GetDoubleArray({});
  entry.SetDoubleArray(value);

  return std::vector<int>(value.begin(), value.end());
}

template <>
void miscar::network::Set(const std::string &path, bool value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetBoolean(value);
}

template <>
void miscar::network::Set(const std::string &path, int value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDouble(value);
}

template <>
void miscar::network::Set(const std::string &path, double value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDouble(value);
}

template <>
void miscar::network::Set(const std::string &path, std::string value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetString(value);
}

template <>
void miscar::network::Set(const std::string &path, std::vector<bool> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetBooleanArray(std::vector<int>(value.begin(), value.end()));
}

template <>
void miscar::network::Set(const std::string &path, std::vector<int> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDoubleArray(std::vector<double>(value.begin(), value.end()));
}

template <>
void miscar::network::Set(const std::string &path, std::vector<double> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDoubleArray(value);
}

template <>
void miscar::network::Set(const std::string &path,
                          std::vector<std::string> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetStringArray(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, bool value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultBoolean(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, int value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultDouble(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, double value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultDouble(value);
}

template <>
void miscar::network::SetDefault(const std::string &path, std::string value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultString(value);
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<bool> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultBooleanArray(std::vector<int>(value.begin(), value.end()));
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<int> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultDoubleArray(std::vector<double>(value.begin(), value.end()));
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<double> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultDoubleArray(value);
}

template <>
void miscar::network::SetDefault(const std::string &path,
                                 std::vector<std::string> value) {
  nt::NetworkTableInstance::GetDefault()
      .GetEntry(Normalize(path))
      .SetDefaultStringArray(value);
}

void miscar::network::Add(const std::string &name, wpi::Sendable &sendable) {
  frc::SmartDashboard::PutData(name, &sendable);
}

std::string miscar::network::Normalize(const std::string &path) {
  if (path[0] == '/') {
    return path;
  }
  return TABLE_PREFIX + path;
}
