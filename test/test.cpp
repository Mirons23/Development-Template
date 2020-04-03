// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "ClassHex.h"

TEST(TestClassHex, _razn1) {
  Hex c2("123B", 4);
  Hex c1("131", 3);
  Hex p = c1 - c2;
  Hex truerez("-EF6", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, _razn2) {
  Hex c2("23A5", 4);
  Hex c1("917", 3);
  Hex p = c1 - c2;
  Hex truerez("-572", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, _razn3) {
  Hex c2("ABC4", 4);
  Hex c1("E3321", 5);
  Hex p = c2 - c1;
  Hex truerez("-78A3", 5);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, summ1) {
  Hex c2("123B", 4);
  Hex c1("131", 3);
  Hex p = c2 + c1;
  Hex truerez("136C", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, summ2) {
  Hex c2("ABC4", 4);
  Hex c1("E3321", 5);
  Hex p = c2 + c1;
  Hex truerez("EDEE5", 5);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, summ3) {
  Hex c2("23A5", 4);
  Hex c1("917", 3);
  Hex p = c2 + c1;
  Hex truerez("2CBC", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, razn1) {
  Hex c2("423B", 4);
  Hex c1("121", 3);
  Hex p = c2 - c1;
  Hex truerez("411A", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, razn2) {
  Hex c2("ABC4", 4);
  Hex c1("B3", 2);
  Hex p = c2 - c1;
  Hex truerez("AB11", 4);
  EXPECT_EQ(p, truerez);
}

TEST(TestClassHex, razn3) {
  Hex c2("23A5", 4);
  Hex c1("911", 3);
  Hex p = c2 - c1;
  Hex truerez("1A94", 4);
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