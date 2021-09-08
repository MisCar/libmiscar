// Copyright (c) MisCar 1574

#pragma once

#include <units/current.h>

#include <memory>
#include <string>
#include <vector>

#include "miscar/PID.h"

namespace miscar {

class Motor {
 public:
  Motor(std::string&& name, int id, int encoder_resolution);

  enum Mode { PercentOutput, Position, Velocity };

  const std::string& GetName();
  int GetId();
  int GetEncoderResolution();
  virtual double GetPercentOutput() = 0;
  virtual double GetPosition() = 0;
  virtual double GetVelocity() = 0;

  virtual void SetOutput(double output, Mode mode) = 0;
  virtual void SetPID(PID pid) = 0;
  virtual void SetCurrentLimit(units::ampere_t limit) = 0;
  virtual void SetPosition(double position) = 0;
  virtual void Brake() = 0;
  virtual void Coast() = 0;

  static std::vector<Motor*>& GetInstances() { return m_instances; }

 private:
  const std::string m_name;
  const int m_id;
  const int m_encoder_resolution;

  static std::vector<Motor*> m_instances;
};

}  // namespace miscar
