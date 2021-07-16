#include <gtest/gtest.h>

#include "miscar/Fix.h"

TEST(Fix, RoundsPositiveToZeroWhenInRange) {
  EXPECT_EQ(miscar::Fix(1.2, 2), 0);
  EXPECT_EQ(miscar::Fix(2.9, 5), 0);
  EXPECT_EQ(miscar::Fix(0, 1), 0);
}

TEST(Fix, RoundsNegativeToZeroWhenInRange) {
  EXPECT_EQ(miscar::Fix(-1.2, 2), 0);
  EXPECT_EQ(miscar::Fix(-2.9, 5), 0);
  EXPECT_EQ(miscar::Fix(0, 1), 0);
}

TEST(Fix, ReturnsOriginalWhenOutsideOfRange) {
  EXPECT_EQ(miscar::Fix(-1.2, 1), -1.2);
  EXPECT_EQ(miscar::Fix(2.9, 2), 2.9);
  EXPECT_EQ(miscar::Fix(24, 10), 24);
}
