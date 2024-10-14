#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, TestLowOxygenSaturation) {
    ASSERT_FALSE(vitalsOk({ 99, 102, 70 }));
}
TEST(Monitor, TestNormalVitals) {
    ASSERT_TRUE(vitalsOk({ 98.1, 70, 98 }));
}
TEST(Monitor, TestLowPulseRate) {
    ASSERT_FALSE(vitalsOk({ 98.1, 55, 98 }));
}
TEST(Monitor, TestHighTemperature) {
    ASSERT_FALSE(vitalsOk({ 103, 70, 98 }));
}

