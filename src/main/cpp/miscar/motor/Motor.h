#include <units/current.h>

#include "miscar/PID.h"


using namespace units;

namespace miscar {

class Motor {
 public:
  enum Mode { PercentOutput, Position, Velocity };

  virtual double GetPercentOutput();
  virtual double GetPosition();
  virtual double GetVelocity();

  virtual void SetOutput(double output, Mode mode);
  virtual void SetPID(PID pid);
  virtual void SetCurrentLimit(ampere_t limit);
  virtual void SetPosition(double position);
  virtual void Brake();
  virtual void Coast();
};

}  // namespace miscar