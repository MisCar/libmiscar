// Copyright (c) MisCar 1574

#pragma once

namespace miscar {

/** PIDF coefficients for closed-loop control. */
struct PID {
  double p;
  double i;
  double d;
  double f;
  double integral_zone;
  int slot;

  PID(double p, double i, double d, double f, double integral_zone = 0,
      int slot = 0);
};

}  // namespace miscar
