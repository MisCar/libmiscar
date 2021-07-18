// Copyright (c) MisCar 1574

#pragma once

#include <optional>
#include <type_traits>
#include <utility>

#include "miscar/motor/decorator/SetpointRemembering.h"

namespace miscar {

template <typename T,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
/** Only set the output if it isn't the same as before */
class Lazy : public SetpointRemembering<T> {
 public:
  explicit Lazy(const T &t) : T(t) {}

  void SetOutput(double output, Motor::Mode mode) override {
    if (output != SetpointRemembering<T>::GetOutput() ||
        mode != SetpointRemembering<T>::GetMode()) {
      T::SetOutput(output, mode);
    }
  }
};

}  // namespace miscar
