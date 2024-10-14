#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, TestLowOxygenSaturation) {
  vitalSigns vitalSign = { 99, 102, 70 };
  ASSERT_FALSE(vitalsOk(vitalSign));
}
TEST(Monitor, TestNormalVitals) {
  vitalSigns vitalSign = { 98.1, 70, 98 };
  ASSERT_TRUE(vitalsOk(vitalSign));
}
TEST(Monitor, TestLowPulseRate) {
  vitalSigns vitalSign = { 98.1, 55, 98 };
  ASSERT_FALSE(vitalsOk(vitalSign));
}
TEST(Monitor, TestHighTemperature) {
  vitalSigns vitalSign = { 103, 70, 98 };
  ASSERT_FALSE(vitalsOk(vitalSign));
}

