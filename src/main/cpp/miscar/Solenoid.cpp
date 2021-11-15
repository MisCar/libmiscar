// Copyright (c) MisCar 1574

#include "miscar/Solenoid.h"

#include <utility>

miscar::Solenoid::Solenoid(std::string name, int port)
    : frc::Solenoid(port), m_name(std::move(name)) {
  m_instances.push_back(this);
}

const std::string &miscar::Solenoid::GetName() { return m_name; }

std::vector<miscar::Solenoid *> &miscar::Solenoid::GetInstances() {
  return m_instances;
}

std::vector<miscar::Solenoid *> miscar::Solenoid::m_instances =
    std::vector<Solenoid *>();