// Copyright (c) MisCar 1574

#include "miscar/can/Pigeon.h"

#include <frc/MathUtil.h>

miscar::Pigeon::Pigeon(int id) : PigeonIMU(id) {}

units::degree_t miscar::Pigeon::GetYaw() {
  double ypr[3];
  GetYawPitchRoll(ypr);

  // The yaw between [-180, 180]
  units::degree_t yaw = frc::AngleModulus(-units::degree_t(ypr[0]));

  return yaw < 0_deg ? yaw + 360_deg : yaw;
}
