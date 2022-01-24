// Copyright (c) MisCar 1574

#include "miscar/Named.h"

miscar::Named::Named(std::string name) : m_name(name) {}

std::string &miscar::Named::GetName() { return m_name; }
