// Copyright (c) MisCar 1574

#pragma once

#include <optional>
#include <type_traits>
#include <utility>

#include "miscar/motor/decorator/SetpointRemembering.h"

namespace miscar {

/** A motor which only runs methods lazily to avoid extra CAN usage. */
template <typename T,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
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
