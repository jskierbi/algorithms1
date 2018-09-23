//
// Created by jakub on 23.09.18.
//
#include "gtest/gtest.h"

using namespace std;

class UnionFindTest : public ::testing::Test {
protected:
    void SetUp() override {
        a = "new";
        b = "new";
    }

    // Define fields here
    string a;
    string b;
};

TEST_F(UnionFindTest, FirstFixtureChange) {
    ASSERT_EQ("new", a);
    ASSERT_EQ("new", b);
    a = "changed";
    b = "changed-again";
    ASSERT_EQ("changed", a);
    ASSERT_EQ("changed-again", b);
}

TEST_F(UnionFindTest, SecondFixtureChange) {
    ASSERT_EQ("new", a);
    ASSERT_EQ("new", b);
    a = "changed";
    b = "changed-again";
    ASSERT_EQ("changed", a);
    ASSERT_EQ("changed-again", b);
}
