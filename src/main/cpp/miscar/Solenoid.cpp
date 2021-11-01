// Copyright (c) MisCar 1574

#include "Solenoid.h"
#include "miscar/Solenoid.h"

miscar::Solenoid::Solenoid(std::string_view name, int port)
    : frc::Solenoid(port), m_name(name) {
  m_instances.push_back(this);
}

std::string_view miscar::Solenoid::GetName() { return m_name; }

std::vector<miscar::Solenoid *> &miscar::Solenoid::GetInstances() {
  return m_instances;
}

std::vector<miscar::Solenoid *> miscar::Solenoid::m_instances =
    std::vector<Solenoid *>();