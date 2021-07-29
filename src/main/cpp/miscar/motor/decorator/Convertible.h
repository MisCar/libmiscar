// Copyright (c) MisCar 1574

#pragma once

#include <type_traits>

#include "miscar/motor/Motor.h"
#include "units/time.h"

namespace miscar {

template <typename T, class distance,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
/** Only set the output if it isn't the same as before */
class Convertible : public T {
 public:
  using distance_t = units::unit_t<distance>;
  using velocity =
      units::compound_unit<distance, units::inverse<units::seconds>>;
  using velocity_t = units::unit_t<velocity>;

  explicit Convertible(const T &t, distance_t ratio) : T(t), m_ratio(ratio) {}

  distance_t GetPosition() { return Motor::GetPosition() * m_ratio; }

 private:
  distance_t m_ratio;
};

}  // namespace miscar
