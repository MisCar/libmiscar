#pragma once

#include <type_traits>

#include "miscar/Log.h"
#include "miscar/motor/Motor.h"

namespace miscar {

template <typename T,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
class LowerLimited : public T {
 public:
  LowerLimited(const T &t, double limit) : T(t), m_limit(limit) {}

  void SetOutput(double output, Motor::Mode mode) override {
    if (mode != Motor::Position) {
      log::Warning(
          "A limited motor shouldn't be set with modes other than position");
    } else {
      if (output < m_limit) output = m_limit;
    }

    T::SetOutput(output, mode);
  }

 private:
  const double m_limit;
};

}  // namespace miscar