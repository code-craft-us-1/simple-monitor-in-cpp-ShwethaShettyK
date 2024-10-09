#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  vitalSigns vitalSign = { 99, 102, 70 };
  ASSERT_FALSE(vitalsOk(vitalSign));

  vitalSign = { 98.1, 70, 98 };
  ASSERT_TRUE(vitalsOk(vitalSign));

  vitalSign = { 98.1, 55, 98 };
  ASSERT_FALSE(vitalsOk(vitalSign));

  vitalSign = { 103, 70, 98 };
  ASSERT_FALSE(vitalsOk(vitalSign));
}

