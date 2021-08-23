#pragma once

#include <string>

namespace miscar::network {

bool GetBool(const std::string& path, bool defaultValue = false);
double GetDouble(const std::string& path, double defaultValue = 0);
std::string GetString(const std::string& path,
                      const std::string& defaultValue = "");

}  // namespace miscar::network