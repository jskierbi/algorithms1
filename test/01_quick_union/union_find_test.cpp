//
// Created by jakub on 23.09.18.
//
#include "gtest/gtest.h"
#include "01_quick_union/union_find.hpp"

using namespace std;

class UnionFindTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    // Define fixture fields here
};

TEST_F(UnionFindTest, AssertWorks) {
    union_find f(5);
    ASSERT_DEATH({ f.find_root(5); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.find_root(-1); }, "Assertion .* failed.");

    ASSERT_DEATH({ f.is_connected(0, -1); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.is_connected(0, 5); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.is_connected(-1, 0); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.is_connected(5, 0); }, "Assertion .* failed.");

    ASSERT_DEATH({ f.make_union(-1, 0); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.make_union(5, 0); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.make_union(0, -1); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.make_union(0, 5); }, "Assertion .* failed.");

    ASSERT_DEATH({ f.find_roots_balanced(-1, 0); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.find_roots_balanced(5, 0); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.find_roots_balanced(0, -1); }, "Assertion .* failed.");
    ASSERT_DEATH({ f.find_roots_balanced(0, 5); }, "Assertion .* failed.");
}

TEST_F(UnionFindTest, SingleUnion) {
    union_find f(10);
    f.make_union(1, 0);
    ASSERT_TRUE(f.is_connected(0, 1));
    ASSERT_TRUE(f.is_connected(1, 1));
    ASSERT_FALSE(f.is_connected(2, 1));
    ASSERT_FALSE(f.is_connected(3, 1));
    ASSERT_FALSE(f.is_connected(4, 1));
    ASSERT_FALSE(f.is_connected(5, 1));
    ASSERT_FALSE(f.is_connected(6, 1));
    ASSERT_FALSE(f.is_connected(7, 1));
    ASSERT_FALSE(f.is_connected(8, 1));
    ASSERT_FALSE(f.is_connected(9, 1));

    ASSERT_EQ(1, f.find_root(0));
    ASSERT_EQ(1, f.find_root(1));
    ASSERT_EQ(2, f.find_root(2));
    ASSERT_EQ(3, f.find_root(3));
    ASSERT_EQ(4, f.find_root(4));
    ASSERT_EQ(5, f.find_root(5));
    ASSERT_EQ(6, f.find_root(6));
    ASSERT_EQ(7, f.find_root(7));
    ASSERT_EQ(8, f.find_root(8));
    ASSERT_EQ(9, f.find_root(9));
}

TEST_F(UnionFindTest, Case1Correct) {
    union_find f(10);
    f.make_union(1, 0);
    f.make_union(1, 2);
    f.make_union(2, 3);
    f.make_union(3, 4);
    f.make_union(4, 5);
    f.make_union(5, 6);
    f.make_union(6, 7);
    f.make_union(7, 8);
    f.make_union(8, 9);

    ASSERT_EQ(1, f.find_root(0));
    ASSERT_EQ(1, f.find_root(1));
    ASSERT_EQ(1, f.find_root(2));
    ASSERT_EQ(1, f.find_root(3));
    ASSERT_EQ(1, f.find_root(4));
    ASSERT_EQ(1, f.find_root(5));
    ASSERT_EQ(1, f.find_root(6));
    ASSERT_EQ(1, f.find_root(7));
    ASSERT_EQ(1, f.find_root(8));
    ASSERT_EQ(1, f.find_root(9));

    ASSERT_EQ(1, f.get_max_depth());
}


TEST_F(UnionFindTest, Case2Correct) {
    union_find f(10);
    f.make_union(4, 3);
    f.make_union(3, 8);
    f.make_union(6, 5);
    f.make_union(9, 4);
    f.make_union(2, 1);
    f.make_union(5, 0);
    f.make_union(7, 2);
    f.make_union(6, 1);
    f.make_union(7, 3);

    ASSERT_EQ(6, f.find_root(0));
    ASSERT_EQ(6, f.find_root(1));
    ASSERT_EQ(6, f.find_root(2));
    ASSERT_EQ(6, f.find_root(3));
    ASSERT_EQ(6, f.find_root(4));
    ASSERT_EQ(6, f.find_root(5));
    ASSERT_EQ(6, f.find_root(6));
    ASSERT_EQ(6, f.find_root(7));
    ASSERT_EQ(6, f.find_root(8));
    ASSERT_EQ(6, f.find_root(9));

    ASSERT_EQ(2, f.get_max_depth());
}
