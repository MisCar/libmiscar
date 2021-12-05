// Copyright (c) MisCar 1574

#include <gtest/gtest.h>

#include <units/length.h>

#include "miscar/can/Falcon.h"
#include "miscar/motor/Convertible.h"

TEST(ConvertibleTest, CanConstruct) {
  miscar::Convertible<miscar::Falcon, units::meter> convertible(
      1_m, std::string("Test"), 0);
  auto &c =
      static_cast<ctre::phoenix::motorcontrol::can::TalonFX &>(convertible);
}
