#include "Fix.h"
#include <cmath>

double miscar::utilities::Fix(double value, double range)
{
  return (abs(value) < range) ? 0 : value;
}