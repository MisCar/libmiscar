// Copyright (c) MisCar 1574

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "miscar/LazyCallback.h"

TEST(LazyCallback, SetsValueWhenSetting) {
  miscar::LazyCallback<int> c(0, [](int x) {});
  EXPECT_EQ(c.Get(), 0);
  c.Set(1);
  EXPECT_EQ(c.Get(), 1);
}

TEST(LazyCallback, CallsCallbackWhenDifferent) {
  int call_count = 0;
  miscar::LazyCallback<int> c(0, [&call_count](int x) { call_count++; });
  EXPECT_EQ(call_count, 0);
  c.Set(1);
  EXPECT_EQ(call_count, 1);
  c.Set(2);
  EXPECT_EQ(call_count, 2);
}

TEST(LazyCallback, DoesNotCallCallbackWhenTheSame) {
  int call_count = 0;
  miscar::LazyCallback<int> c(0, [&call_count](int x) { call_count++; });
  EXPECT_EQ(call_count, 0);
  c.Set(0);
  EXPECT_EQ(call_count, 0);
  c.Set(0);
  EXPECT_EQ(call_count, 0);
}
