#include <gtest/gtest.h>

#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>
#include <cmath>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(ApprovalTest, HelloWorld) {
    ApprovalTests::Approvals::verify("Hello world");
}

bool undefinedBehavior1() {
    int a = 0;
    int b = 0;
    return &a < &b;
}

TEST(GTest, undefinedBehavior) {
    EXPECT_EQ(undefinedBehavior1(), false);
}
