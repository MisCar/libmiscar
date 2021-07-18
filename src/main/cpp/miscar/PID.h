#pragma once

namespace miscar {

struct PID {
  double p;
  double i;
  double d;
  double f;
  double integral_zone;
  int slot = 0;
};

}  // namespace miscar