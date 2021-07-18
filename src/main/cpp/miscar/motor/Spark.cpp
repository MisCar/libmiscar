// Copyright (c) MisCar 1574

#include "miscar/motor/Spark.h"

#include <rev/CANSparkMax.h>

using namespace miscar;
using namespace units;

Spark::Spark(int id)
    : rev::CANSparkMax(id, rev::CANSparkMax::MotorType::kBrushless) {}

double Spark::GetPercentOutput() { return CANSparkMax::GetAppliedOutput(); }

double Spark::GetPosition() { return CANSparkMax::GetEncoder().GetPosition(); }

double Spark::GetVelocity() { return CANSparkMax::GetEncoder().GetVelocity(); }

void Spark::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      CANSparkMax::Set(output);
      break;
    case Position:
      CANSparkMax::GetPIDController().SetReference(output,
                                                   rev::ControlType::kPosition);
      break;
    case Velocity:
      CANSparkMax::GetPIDController().SetReference(output,
                                                   rev::ControlType::kVelocity);
      break;
  }
}

void Spark::SetPID(PID pid) {
  auto controller = CANSparkMax::GetPIDController();

  controller.SetP(pid.p);
  controller.SetI(pid.i);
  controller.SetD(pid.d);
  controller.SetFF(pid.f);
  controller.SetIZone(pid.integral_zone);
}

void Spark::SetCurrentLimit(ampere_t limit) {
  CANSparkMax::SetSmartCurrentLimit(limit.value());
}

void Spark::SetPosition(double position) {
  CANSparkMax::GetEncoder().SetPosition(position);
}

void Spark::Brake() {
  CANSparkMax::SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void Spark::Coast() {
  CANSparkMax::SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}
