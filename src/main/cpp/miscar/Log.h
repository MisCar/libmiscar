// Copyright (c) MisCar 1574

#pragma once

#include <string>

namespace miscar::log {

/** Log a warning to the Driver Station console. */
void Warning(const std::string& message);

/** Log an error to the Driver Station console. */
void Error(const std::string& message);

}  // namespace miscar::log
