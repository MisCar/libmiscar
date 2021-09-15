// Copyright (c) MisCar 1574

#pragma once

#include <string>

#include "frc/smartdashboard/Sendable.h"

namespace miscar::network {

template <typename T>
T Get(const std::string& path);

template <typename T>
void Set(const std::string& path, T value);

void Add(const std::string& path, frc::Sendable& sendable);

}  // namespace miscar::network
