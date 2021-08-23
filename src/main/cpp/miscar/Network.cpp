#include "Network.h"
#include "networktables/NetworkTableInstance.h"

using namespace miscar;

bool network::GetBool(const std::string &path, bool defaultValue) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry("MisCar/" + path)
      .GetBoolean(defaultValue);
}

double network::GetDouble(const std::string &path, double defaultValue) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry("MisCar/" + path)
      .GetDouble(defaultValue);
}

std::string network::GetString(const std::string &path,
                               const std::string &defaultValue) {
  return nt::NetworkTableInstance::GetDefault()
      .GetEntry("MisCar/" + path)
      .GetString(defaultValue);
}