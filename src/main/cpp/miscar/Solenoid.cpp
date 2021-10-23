// Copyright (c) MisCar 1574

#include "Solenoid.h"
#include "miscar/Solenoid.h"

miscar::Solenoid::Solenoid(int port) : frc::Solenoid(port) {
  m_instances.push_back(this);
}

std::vector<miscar::Solenoid *> &miscar::Solenoid::GetInstances() {
  return m_instances;
}
