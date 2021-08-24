// Copyright (c) MisCar 1574

#include "miscar/motor/Spark.h"

#include <rev/CANSparkMax.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr int NEO_ENCODER_RESOLUTION = 4096;

miscar::Spark::Spark(std::string&& name, int id)
    : Motor(std::move(name), id, NEO_ENCODER_RESOLUTION),
      rev::CANSparkMax(id, rev::CANSparkMax::MotorType::kBrushless) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::SPARK) {
    log::Warning(GetName() +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::SPARK) + " is available.");
  }
}

double miscar::Spark::GetPercentOutput() { return GetAppliedOutput(); }

double miscar::Spark::GetPosition() { return GetEncoder().GetPosition(); }

double miscar::Spark::GetVelocity() { return GetEncoder().GetVelocity(); }

void miscar::Spark::SetOutput(double output, Mode mode) {
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

void miscar::Spark::SetPID(PID pid) {
  auto controller = CANSparkMax::GetPIDController();

  controller.SetP(pid.p);
  controller.SetI(pid.i);
  controller.SetD(pid.d);
  controller.SetFF(pid.f);
  controller.SetIZone(pid.integral_zone);
}

void miscar::Spark::SetCurrentLimit(units::ampere_t limit) {
  CANSparkMax::SetSmartCurrentLimit(limit.value());
}

void miscar::Spark::SetPosition(double position) {
  CANSparkMax::GetEncoder().SetPosition(position);
}

void miscar::Spark::Brake() {
  CANSparkMax::SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void miscar::Spark::Coast() {
  CANSparkMax::SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}
