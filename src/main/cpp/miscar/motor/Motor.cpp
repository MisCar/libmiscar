// Copyright (c) MisCar 1574

#include "miscar/motor/Motor.h"

using namespace miscar;

Motor::Motor(const std::string& name, int id, int encoder_resolution)
    : m_name(name), m_id(id), m_encoder_resolution(encoder_resolution) {
#ifdef RUNNING_SYSTEM_CHECKS
  GetInstances().push_back(this);
#endif
}

const std::string& Motor::GetName() { return m_name; }

int Motor::GetId() { return m_id; }

#ifdef RUNNING_SYSTEM_CHECKS
std::vector<Motor*> Motor::m_instances = std::vector<Motor*>();
#endif
