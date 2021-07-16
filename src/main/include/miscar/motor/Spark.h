#include <rev/CANSparkMax.h>

#include "miscar/motor/Motor.h"

namespace miscar {

/** Used for NEO motors. We only use Sparks for brushless motors */
class Spark : public Motor, public rev::CANSparkMax {
 public:
  explicit Spark(int id);

  double GetPercentOutput() override;
  double GetPosition() override;
  double GetVelocity() override;

  void SetOutput(double output, Mode mode) override;
  void SetPID(PID pid) override;
  void SetCurrentLimit(ampere_t limit) override;
  void SetPosition(double position) override;
  void Brake() override;
  void Coast() override;
};

}  // namespace miscar