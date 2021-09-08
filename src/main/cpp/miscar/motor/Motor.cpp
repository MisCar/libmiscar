// Copyright (c) MisCar 1574

#include "miscar/motor/Motor.h"

miscar::Motor::Motor(std::string&& name, int id, int encoder_resolution)
    : m_name(name), m_id(id), m_encoder_resolution(encoder_resolution) {
  GetInstances().push_back(this);
}

const std::string& miscar::Motor::GetName() { return m_name; }

int miscar::Motor::GetId() { return m_id; }

int miscar::Motor::GetEncoderResolution() { return m_encoder_resolution; }

std::vector<miscar::Motor*> miscar::Motor::m_instances = std::vector<Motor*>();
