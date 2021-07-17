#pragma once

#include <string>

namespace miscar::log {

void Warning(const std::string& message);
void Error(const std::string& message);

void Network(const std::string& path, const std::string& message);
void Network(const std::string& path, bool value);
void Network(const std::string& path, double value);

}  // namespace miscar::log