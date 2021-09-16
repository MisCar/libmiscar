// Copyright (c) MisCar 1574

#pragma once

#include <string>

#include "frc/smartdashboard/Sendable.h"

namespace miscar::network {

/** Get a value from the Network Tables. */
template <typename T>
T Get(const std::string& path);

/** Set a value in the Network Tables. */
template <typename T>
void Set(const std::string& path, T value);

/** Add a sendable to Network Tables. */
void Add(const std::string& path, frc::Sendable& sendable);

}  // namespace miscar::network
