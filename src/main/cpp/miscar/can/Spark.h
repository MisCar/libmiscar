// Copyright (c) MisCar 1574

#pragma once

#include <string>
#include <vector>

#include <rev/CANSparkMax.h>

#include "miscar/motor/Motor.h"

namespace miscar {

/**
 * AKA REV Robotics Spark Max.
 * https://www.revrobotics.com/rev-11-2158/
 * Used for NEO motors.
 * We only use Sparks with brushless NEOs.
 */
class Spark : public Motor, public rev::CANSparkMax {
 public:
  Spark(std::string name, int id);

  double GetPercentOutput() override;
  double GetPosition() override;
  double GetVelocity() override;

  void SetOutput(double output, Mode mode) override;
  void SetPID(PID pid) override;
  void SetCurrentLimit(units::ampere_t limit) override;
  void SetPosition(double position) override;
  void Brake() override;
  void Coast() override;
  void Invert() override;
  void Follow(Spark &spark);
  /** Intended for internal use */
  void AddFollower(rev::CANSparkMax &spark);

 private:
  rev::SparkMaxRelativeEncoder m_encoder;
  rev::SparkMaxPIDController m_controller;
  rev::CANSparkMax *m_leader;
  std::vector<rev::CANSparkMax *> m_followers;
};

}  // namespace miscar
