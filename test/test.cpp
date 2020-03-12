// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "ClassHex.h"

TEST(TestClassHex, add) {
  Hex c2("123B", 4);
  Hex c1("131", 3);
  Hex p = c2 + c1;
  Hex truerez("136C", 5);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, ConstructorCopyRight) {
  Hex c2("123B", 4);
  Hex c1(c2);
  EXPECT_EQ(c1, c2);
}

TEST(TestClassHex, CanPrisvoit) {
  Hex c2("543", 3);
  Hex c1;
  ASSERT_NO_THROW(c1 = c2);
}

TEST(TestClassHex, CanRightPrisvoit) {
  Hex c2("A33", 3);
  Hex c1 = c2;
  EXPECT_EQ(c1, c2);
}

TEST(TestClassHex, CanSravn) {
  Hex c2("3567", 4);
  Hex c1("3567", 4);
  ASSERT_NO_THROW(c1 == c2);
}

TEST(TestClassHex, CanRightSravn1) {
  Hex c2("543", 3);
  Hex c1 = c2;
  EXPECT_EQ(true, c1 == c2);
}

TEST(TestClassHex, CanRightSravn2) {
  Hex c2("ABC4", 4);
  Hex c1("E3321", 5);
  EXPECT_EQ(false, c1 == c2);
}