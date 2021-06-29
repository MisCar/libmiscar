#include "utilities/Fix.h"
#include <cmath>

double miscar::utilities::Fix(double value, double range)
{
  return (std::abs(value) < range) ? 0 : value;
}
