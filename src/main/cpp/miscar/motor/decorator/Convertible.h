// Copyright (c) MisCar 1574

#pragma once

#include <type_traits>

#include <units/time.h>

#include "miscar/Log.h"
#include "miscar/motor/Motor.h"

namespace miscar {

/** A motor with an encoder which evaluates to a real-life measurement. */
template <typename T, class distance,
          typename = std::enable_if<std::is_base_of<T, Motor>::value>>
class Convertible : public T {
 public:
  using distance_t = units::unit_t<distance>;
  using velocity =
      units::compound_unit<distance, units::inverse<units::seconds>>;
  using velocity_t = units::unit_t<velocity>;

  /**
   * @param ratio The amount of distance units in a tick.
   */
  explicit Convertible(const T &t, distance_t ratio) : T(t), m_ratio(ratio) {}

  distance_t GetConvertedPosition() { return Motor::GetPosition() * m_ratio; }

  velocity_t GetConvertedVelocity() {
    return Motor::GetVelocity() / 1_s * m_ratio;
  }

  double GetPosition() {
    miscar::log::Warning(
        "You shouldn't get unconverted position on a convertible motor");
    return T::GetPosition();
  }

  double GetVelocity() {
    miscar::log::Warning(
        "You shouldn't get unconverted velocity on a convertible motor");
    return T::GetVelocity();
  }

  void SetPosition(distance_t position) { SetPosition(position / m_ratio); }

  void SetOutput(distance_t output) {
    auto rotations = output / m_ratio;
    SetOutput(rotations, Motor::Mode::Position);
  }

  void SetOutput(velocity_t output) {
    auto rotations_per_second = output / m_ratio * 1_s;
    SetOutput(rotations_per_second, Motor::Mode::Velocity);
  }

 private:
  distance_t m_ratio;
};

}  // namespace miscar
