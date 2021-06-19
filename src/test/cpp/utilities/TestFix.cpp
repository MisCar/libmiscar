#include "utilities/Fix.h"
#include <gtest/gtest.h>

TEST(Fix, RoundsPositiveToZeroWhenInRange)
{
  EXPECT_EQ(miscar::utilities::Fix(1.2, 2), 0);
  EXPECT_EQ(miscar::utilities::Fix(2.9, 5), 0);
  EXPECT_EQ(miscar::utilities::Fix(0, 1), 0);
}

TEST(Fix, RoundsNegativeToZeroWhenInRange)
{
  EXPECT_EQ(miscar::utilities::Fix(-1.2, 2), 0);
  EXPECT_EQ(miscar::utilities::Fix(-2.9, 5), 0);
  EXPECT_EQ(miscar::utilities::Fix(0, 1), 0);
}

TEST(Fix, ReturnsOriginalWhenOutsideOfRange)
{
  EXPECT_EQ(miscar::utilities::Fix(-1.2, 1), -1.2);
  EXPECT_EQ(miscar::utilities::Fix(2.9, 2), 2.9);
  EXPECT_EQ(miscar::utilities::Fix(0.24, 0.1), 0.24);
}
