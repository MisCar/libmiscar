// Copyright (c) MisCar 1574

#pragma once

namespace miscar {

struct PID {
  double p;
  double i;
  double d;
  double f;
  double integral_zone = 0;
  int slot = 0;
};

}  // namespace miscar
