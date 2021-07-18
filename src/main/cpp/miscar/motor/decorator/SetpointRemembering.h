#pragma once

#include <optional>
#include <type_traits>
#include <utility>

#include "miscar/motor/Motor.h"

namespace miscar {

template <typename T,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
class SetpointRemembering : public T {
 public:
  SetpointRemembering(const T &t) : T(t) {}

  void SetOutput(double output, Motor::Mode mode) override {
    m_output = output;
    m_mode = mode;
    T::SetOutput(output, mode);
  }

  std::optional<double> GetOutput() { return m_output; }
  std::optional<Motor::Mode> GetMode() { return m_mode; }

 private:
  std::optional<double> m_output;
  std::optional<Motor::Mode> m_mode;
};

}  // namespace miscar