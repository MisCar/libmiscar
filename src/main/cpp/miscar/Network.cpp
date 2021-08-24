// Copyright (c) MisCar 1574

#include "Network.h"

#include <networktables/NetworkTableInstance.h>

#include <string>

using namespace miscar;

template <>
bool network::Get<bool>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault().GetEntry(path).GetBoolean(
      false);
}

template <>
int network::Get<int>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault().GetEntry(path).GetDouble(0);
}

template <>
double network::Get<double>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault().GetEntry(path).GetDouble(0);
}

template <>
std::string network::Get<std::string>(const std::string &path) {
  return nt::NetworkTableInstance::GetDefault().GetEntry(path).GetString("");
}
