#include <gtest/gtest.h>

#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>
#include <cmath>
#include <ostream>
#include <fstream>

#include "blackbox.h"

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

TEST(ApprovalTest, DataIngestion) {
    // loading of input data
    std::ifstream in("../src/data.txt");
    EXPECT_TRUE(in.good());
    std::vector<std::string> input;

    std::string str;
    while(getline(in, str))
    {
        input.push_back(str);
    }

    // processing of input data
    blackbox::process(input);

    // conversion to string-based representation
    std::ostringstream out;
    for(const auto& line : input) {
        out << line << "\n";
    }

    // verify the output
    ApprovalTests::Approvals::verify(out.str());
}

bool undefinedBehavior1() {
    int a = 0;
    int b = 0;
    return &a < &b;
}

TEST(GTest, undefinedBehavior) {
    EXPECT_EQ(undefinedBehavior1(), false);
}
