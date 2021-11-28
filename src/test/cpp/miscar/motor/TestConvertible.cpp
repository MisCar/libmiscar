#include <gtest/gtest.h>
#include <units/length.h>

#include "miscar/device/Falcon.h"
#include "miscar/motor/Convertible.h"

TEST(ConvertibleTest, CanConstruct) {
  miscar::Convertible<miscar::Falcon, units::meter> convertible(1_m, "Test", 0);
  auto &c =
      static_cast<ctre::phoenix::motorcontrol::can::TalonFX &>(convertible);
}