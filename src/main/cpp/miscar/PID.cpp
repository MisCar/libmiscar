// Copyright (c) MisCar 1574

#include "miscar/PID.h"

constexpr miscar::PID::PID(double p, double i, double d, double f, double integral_zone,
                 int slot)
    : p(p), i(i), d(d), f(f), integral_zone(integral_zone), slot(slot) {}
