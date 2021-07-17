#include <optional>
#include <type_traits>
#include <utility>

#include "miscar/motor/Motor.h"

namespace miscar {

template <class M, typename = std::enable_if<std::is_base_of<M, Motor>::value>>
class SetpointRemembering : public M {
 public:
  SetpointRemembering(const M &m) : M(m) {}

  void SetOutput(double output, Motor::Mode mode) override {
    m_output = output;
    m_mode = mode;
    M::SetOutput(output, mode);
  }

  std::optional<double> GetOutput() { return m_output; }
  std::optional<Motor::Mode> GetMode() { return m_mode; }

 private:
  std::optional<double> m_output;
  std::optional<Motor::Mode> m_mode;
};

}  // namespace miscar