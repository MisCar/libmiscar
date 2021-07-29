// Copyright (c) MisCar 1574

#include "miscar/motor/Spark.h"

#include <rev/CANSparkMax.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

using namespace miscar;
using namespace units;

constexpr int NEO_ENCODER_RESOLUTION = 4096;

Spark::Spark(const std::string& name, int id)
    : rev::CANSparkMax(id, rev::CANSparkMax::MotorType::kBrushless),
      Motor(name, id, NEO_ENCODER_RESOLUTION) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::SPARK) {
    log::Warning(GetName() +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::SPARK) + " is available.");
  }
}

double Spark::GetPercentOutput() { return GetAppliedOutput(); }

double Spark::GetPosition() { return GetEncoder().GetPosition(); }

double Spark::GetVelocity() { return GetEncoder().GetVelocity(); }

void Spark::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      Set(output);
      break;
    case Position:
      GetPIDController().SetReference(output, rev::ControlType::kPosition);
      break;
    case Velocity:
      GetPIDController().SetReference(output, rev::ControlType::kVelocity);
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
