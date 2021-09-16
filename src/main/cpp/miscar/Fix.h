// Copyright (c) MisCar 1574

#pragma once

namespace miscar {

/**
 * Round the value to 0 if its magnitude is smaller than the range.
 * Mostly used to avoid joystick drifting.
 */
double Fix(double value, double range);

}  // namespace miscar
