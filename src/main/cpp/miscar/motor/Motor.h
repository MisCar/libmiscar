#pragma once

#include <units/current.h>

#include "miscar/PID.h"

using namespace units;

namespace miscar {

class Motor {
 public:
  enum Mode { PercentOutput, Position, Velocity };

  virtual double GetPercentOutput() = 0;
  virtual double GetPosition() = 0;
  virtual double GetVelocity() = 0;

  virtual void SetOutput(double output, Mode mode) = 0;
  virtual void SetPID(PID pid) = 0;
  virtual void SetCurrentLimit(ampere_t limit) = 0;
  virtual void SetPosition(double position) = 0;
  virtual void Brake() = 0;
  virtual void Coast() = 0;
};

}  // namespace miscar
