// Copyright (c) MisCar 1574

#include "miscar/device/Solenoid.h"

miscar::Solenoid::Solenoid(std::string name) : Named(name) {
  m_instances.push_back(this);
}

void miscar::Solenoid::Flip() { Set(!Get()); }

std::vector<miscar::Solenoid *> miscar::Solenoid::m_instances =
    std::vector<miscar::Solenoid *>();

std::vector<miscar::Solenoid *> &miscar::Solenoid::GetInstances() {
  return m_instances;
}
