// Copyright (c) MisCar 1574

#include "miscar/can/Spark.h"

#include <rev/CANSparkMax.h>
#include <units/time.h>

#include "miscar/Firmware.h"
#include "miscar/Log.h"

constexpr int NEO_ENCODER_RESOLUTION = 4096;
constexpr auto NEO_VELOCITY_SAMPLE_RATE = 100_ms;

miscar::Spark::Spark(std::string name, int id)
    : Motor(name, id, NEO_ENCODER_RESOLUTION),
      CANSparkMax(id, MotorType::kBrushless),
      m_encoder(GetEncoder()) {
  const int current_firmware = GetFirmwareVersion();
  if (current_firmware != firmware::SPARK) {
    log::Warning(std::string(GetName()) +
                 " has outdated firmware: " + std::to_string(current_firmware) +
                 " when " + std::to_string(firmware::SPARK) + " is available.");
  }

  RestoreFactoryDefaults();
  SetInverted(false);
}

double miscar::Spark::GetPercentOutput() { return GetAppliedOutput(); }

double miscar::Spark::GetPosition() {
  return m_encoder.GetPosition() / NEO_ENCODER_RESOLUTION;
}

double miscar::Spark::GetVelocity() {
  return m_encoder.GetVelocity() / NEO_ENCODER_RESOLUTION /
         NEO_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value();
}

void miscar::Spark::SetOutput(double output, Mode mode) {
  switch (mode) {
    case PercentOutput:
      Set(output);
      break;
    case Position:
      GetPIDController().SetReference(output * NEO_ENCODER_RESOLUTION,
                                      rev::CANSparkMax::ControlType::kPosition);
      break;
    case Velocity:
      GetPIDController().SetReference(
          output * NEO_ENCODER_RESOLUTION *
              NEO_VELOCITY_SAMPLE_RATE.convert<units::seconds>().value(),
          rev::CANSparkMax::ControlType::kVelocity);
      break;
  }
}

void miscar::Spark::SetPID(PID pid) {
  auto controller = GetPIDController();

  controller.SetP(pid.p);
  controller.SetI(pid.i);
  controller.SetD(pid.d);
  controller.SetFF(pid.f);
  controller.SetIZone(pid.integral_zone);
}

void miscar::Spark::SetCurrentLimit(units::ampere_t limit) {
  SetSmartCurrentLimit(limit.value());
}

void miscar::Spark::SetPosition(double position) {
  m_encoder.SetPosition(position / NEO_ENCODER_RESOLUTION);
}

void miscar::Spark::Brake() { SetIdleMode(rev::CANSparkMax::IdleMode::kBrake); }

void miscar::Spark::Coast() { SetIdleMode(rev::CANSparkMax::IdleMode::kCoast); }

void miscar::Spark::Invert() { SetInverted(true); }
