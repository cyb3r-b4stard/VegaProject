#include <gtest/gtest.h>
#include "include/fact.h"

TEST(TestFactorial, TestPositive) {
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(6), 720);
    EXPECT_EQ(factorial(7), 5040);
}

TEST(TestFactorial, TestZero) {
    EXPECT_EQ(factorial(0), 1);
}

TEST(TestFactorial, TestNegative) {
    for (int i = 1; i <= -10; ++i) {
        EXPECT_LT(factorial(-i), 0);
    }
}