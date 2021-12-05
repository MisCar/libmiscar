// Copyright (c) MisCar 1574

#include "miscar/pwm/Talon.h"

#include "miscar/Log.h"

miscar::pwm::Talon::Talon(std::string name, int id)
    : miscar::Motor(name, id, 0), frc::Talon(id) {}

void miscar::pwm::Talon::SetOutput(double output, Mode mode) {
  if (mode != PercentOutput) {
    log::Error(
        "A PWM motor controller cannot be set to anything other than percent "
        "output!");
    return;
  }

  Set(output);
}

void miscar::pwm::Talon::SetPID(PID pid) {
  log::Error("A PWM motor controller cannot use PID control!");
}

void miscar::pwm::Talon::SetCurrentLimit(units::ampere_t limit) {
  log::Error("A PWM motor controller doesn't support a current limit!");
}

void miscar::pwm::Talon::SetPosition(double position) {
  log::Error("A PWM motor controller doesn't have an encoder!");
}

void miscar::pwm::Talon::Brake() {
  log::Error("A PWM motor controller can't set a neutral mode!");
}

void miscar::pwm::Talon::Coast() {
  log::Error("A PWM motor controller can't set a neutral mode!");
}

void miscar::pwm::Talon::Invert() { SetInverted(true); }
