/**
 * @file test_data_utils.cpp
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Unit tests for data utils
 * @version 0.1
 * @date 2023-04-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "basis/data_utils.h"

#include "gtest/gtest.h"

TEST(UtilsTest, LinspaceTestWithoutEndPoint) {
  const int n = 4;
  const vec_T<decimal_t> v = {0.0, 0.25, 0.5, 0.75};

  // Generate linspace without including end value
  const vec_T<decimal_t> l = generate_linspace<decimal_t>(0.0, 1.0, n, false);

  for (int i = 0; i < n; i++) {
    EXPECT_NEAR(v[i], l[i], 1e-6);
  }
}

TEST(UtilsTest, LinspaceTestWithEndPoint) {
  const int n = 5;
  const vec_T<decimal_t> v = {0.0, 0.25, 0.5, 0.75, 1.0};

  // Generate linspace with end value included
  const auto l = generate_linspace<decimal_t>(0.0, 1.0, n, true);

  for (int i = 0; i < n; i++) {
    EXPECT_NEAR(v[i], l[i], 1e-6);
  }
}

TEST(UtilsTest, GeneratingVectorOfValuesTest) {
  const int n = 5;
  const decimal_t value = 0.0;
  const vec_T<decimal_t> v(n, value);

  // Generate vector of size n with values
  const auto l = generate_vector_of_values<decimal_t>(n, value);

  for (int i = 0; i < n; i++) {
    EXPECT_NEAR(v[i], l[i], 1e-6);
  }
}

TEST(UtilsTest, FactorialTest) {
  EXPECT_EQ(factorial(0), 1);
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(4), 24);
  EXPECT_EQ(factorial(5), 120);
  EXPECT_EQ(factorial(10), 3628800);
}

TEST(UtilsTest, BinomialCoefficientTest) {
  EXPECT_EQ(binomial(0, 0), 1);
  EXPECT_EQ(binomial(1, 0), 1);
  EXPECT_EQ(binomial(100, 0), 1);
  EXPECT_EQ(binomial(4, 2), 6);
}