#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, TestVitalsOk) {
    ASSERT_FALSE(vitalsOk({ 99, 102, 70 }));
    ASSERT_TRUE(vitalsOk({ 98.1, 70, 98 }));
    ASSERT_FALSE(vitalsOk({ 98.1, 55, 98 }));
    ASSERT_FALSE(vitalsOk({ 103, 70, 98 }));
}
