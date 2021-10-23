// Copyright (c) MisCar 1574

#pragma once

#include <units/current.h>

#include <memory>
#include <string>
#include <vector>

#include "miscar/PID.h"

namespace miscar {

/** A common interface for all motor controllers to implement. */
class Motor {
 public:
  Motor(std::string&& name, int id, int encoder_resolution);

  enum Mode { PercentOutput, Position, Velocity };

  /** Get the name of the motor. */
  const std::string& GetName();
  /** Get the CAN ID of the motor. */
  int GetId();
  /** Get the resolution (counts per revolution) of the motor's encoder. */
  int GetEncoderResolution();

  /** Get the current output in percentage (between -1 and 1). */
  virtual double GetPercentOutput() = 0;
  /** Get the current position of the motor's encoder in rotations. */
  virtual double GetPosition() = 0;
  /**
   * Get the current velocity of the motor's encoder in rotations per second.
   */
  virtual double GetVelocity() = 0;

  /** Set the output of the motor. */
  virtual void SetOutput(double output, Mode mode) = 0;
  /** Set the PID coefficients for the motor control. */
  virtual void SetPID(PID pid) = 0;
  /** Set a current limit for the motor. */
  virtual void SetCurrentLimit(units::ampere_t limit) = 0;
  /** Set the current position of the motor's encoder in rotations. */
  virtual void SetPosition(double position) = 0;
  /** Set the motor to actively prevent movement when set to 0.  */
  virtual void Brake() = 0;
  /** Set the motor to move freely when set to 0. */
  virtual void Coast() = 0;
  /** Invert the direction of the motor. */
  virtual void Invert() = 0;

  /** All of the motors. */
  static std::vector<Motor*>& GetInstances();

 private:
  const std::string m_name;
  const int m_id;
  const int m_encoder_resolution;

  static std::vector<Motor*> m_instances;
};

}  // namespace miscar
