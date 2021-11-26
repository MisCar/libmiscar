// Copyright (c) MisCar 1574

#pragma once

#include <ctre/phoenix/sensors/PigeonIMU.h>
#include <units/angle.h>

namespace miscar {

/**
 * CTRE's Gadgeteer Pigeon IMU accelerometer and gyro.
 * https://www.ctr-electronics.com/gadgeteer-imu-module-pigeon.html
 */
class Pigeon : public ctre::phoenix::sensors::PigeonIMU {
 public:
  explicit Pigeon(int id);

  /** Returns the yaw between [0, 360] degrees. */
  units::degree_t GetYaw();
};

}  // namespace miscar
