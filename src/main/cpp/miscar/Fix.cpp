#include "miscar/Fix.h"

#include <cmath>

using namespace miscar;

double Fix(double value, double range) {
  return (std::abs(value) < range) ? 0 : value;
}
