#include <optional>
#include <type_traits>
#include <utility>

#include "miscar/motor/decorator/SetpointRemembering.h"

namespace miscar {

template <class M, typename = std::enable_if<std::is_base_of<M, Motor>::value>>
/** Only set the output if it isn't the same as before */
class Lazy : public SetpointRemembering<M> {
 public:
  Lazy(const M &m) : M(m) {}

  void SetOutput(double output, Motor::Mode mode) override {
    if (output != SetpointRemembering<M>::GetOutput() ||
        mode != SetpointRemembering<M>::GetMode())
      M::SetOutput(output, mode);
  }
};

}  // namespace miscar