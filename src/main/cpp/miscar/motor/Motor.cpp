// Copyright (c) MisCar 1574

#include "miscar/motor/Motor.h"

using namespace miscar;

Motor::Motor(const std::string& name, int id, int encoder_resolution)
    : m_name(name), m_id(id), m_encoder_resolution(encoder_resolution) {}

const std::string& Motor::GetName() { return m_name; }

int Motor::GetId() { return m_id; }
