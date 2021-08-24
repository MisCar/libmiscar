// Copyright (c) MisCar 1574

#include "miscar/motor/Motor.h"

miscar::Motor::Motor(std::string&& name, int id, int encoder_resolution)
    : m_name(name), m_id(id), m_encoder_resolution(encoder_resolution) {
#ifdef RUNNING_SYSTEM_CHECKS
  GetInstances().push_back(this);
#endif
}

const std::string& miscar::Motor::GetName() { return m_name; }

int miscar::Motor::GetId() { return m_id; }

#ifdef RUNNING_SYSTEM_CHECKS
std::vector<Motor*> Motor::m_instances = std::vector<Motor*>();
#endif
