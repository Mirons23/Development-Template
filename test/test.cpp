// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "Classlonglong.h"

TEST(TestClasslonglong, Add) {
  longlong c11(0, 5);
  longlong c12(0, 5);
  longlong p = c11 + c12;
  longlong truep(0, 10);
  EXPECT_EQ(p, truep);
}

TEST(TestClasslonglong, Minus) {
  longlong c11(133, 5);
  longlong c12(133, 5);
  longlong p = c11 - c12;
  longlong truep(0, 0);
  EXPECT_EQ(p, truep);
}

TEST(TestClasslonglong, Umnozhenie) {
  longlong c11(0, 5);
  longlong c12(0, 5);
  longlong p = c11 * c12;
  longlong truep(0, 25);
  EXPECT_EQ(p, truep);
}

TEST(TestClasslonglong, Delenie) {
  longlong c11(1, 5);
  longlong c12(0, 5);
  longlong p = c11 / c12;
  longlong truep(0, 200000001);
  EXPECT_EQ(p, truep);
}

TEST(TestClasslonglong, ConstructorDefaultRight) {
  longlong c1;
  longlong c2(0, 0);
  EXPECT_EQ(c1, c2);
}

TEST(TestClasslonglong, ConstructorCopyRight) {
  longlong c2(34, 43342);
  longlong c1(c2);
  EXPECT_EQ(c1, c2);
}

TEST(TestClasslonglong, CanPrisvoit) {
  longlong c2(543, 54523);
  longlong c1;
  ASSERT_NO_THROW(c1 = c2);
}

TEST(TestClasslonglong, CanRightPrisvoit) {
  longlong c2(33, 5636);
  longlong c1 = c2;
  EXPECT_EQ(c1, c2);
}

TEST(TestClasslonglong, CanSravn) {
  longlong c2(3567, 3453);
  longlong c1(3567, 3453);
  ASSERT_NO_THROW(c1 == c2);
}

TEST(TestClasslonglong, CanRightSravn1) {
  longlong c2(543, 5332);
  longlong c1 = c2;
  EXPECT_EQ(true, c1 == c2);
}

TEST(TestClasslonglong, CanRightSravn2) {
  longlong c2(3321, 3789);
  longlong c1(3321, 4765);
  EXPECT_EQ(false, c1 == c2);
}

TEST(TestClasslonglong, CanDiv) {
  longlong c2(33, 43);
  longlong c1(33, 47);
  ASSERT_NO_THROW(c1 / c2);
}

TEST(TestClasslonglong, CantDivByZero) {
  longlong c2(0, 0);
  longlong c1(33, 17);
  ASSERT_NO_THROW(c1 / c2);
}

TEST(TestClasslonglong, CanPrint) {
  longlong c1(35, 7122);
  ASSERT_NO_THROW();
}

TEST(TestClasslonglong, CanSubTwoPositiveNumbers) {
  longlong c1(543, 3455), c2(543, 3455);
  longlong res = c1 - c2;
  longlong trueRes(0, 0);
  EXPECT_EQ(res, trueRes);
}