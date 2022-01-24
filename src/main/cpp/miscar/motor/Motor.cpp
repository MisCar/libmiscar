// Copyright (c) MisCar 1574

#include "miscar/motor/Motor.h"

#include <utility>

miscar::Motor::Motor(std::string name, int id, int encoder_resolution)
    : Named(name), m_id(id), m_encoder_resolution(encoder_resolution) {
  GetInstances().push_back(this);
}

int miscar::Motor::GetId() { return m_id; }

int miscar::Motor::GetEncoderResolution() { return m_encoder_resolution; }

std::vector<miscar::Motor*> miscar::Motor::m_instances = std::vector<Motor*>();

std::vector<miscar::Motor*>& miscar::Motor::GetInstances() {
  return m_instances;
}

double miscar::Motor::GetRPM() { return GetVelocity() * 60; }

void miscar::Motor::SetRPM(double rpm) { SetOutput(rpm * 60, Mode::Velocity); }
