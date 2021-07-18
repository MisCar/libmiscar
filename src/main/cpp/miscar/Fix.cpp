// Copyright (c) MisCar 1574

#include "miscar/Fix.h"

#include <cmath>

double miscar::Fix(double value, double range) {
  return (std::abs(value) < range) ? 0 : value;
}
