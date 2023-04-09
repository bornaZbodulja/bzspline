/**
 * @file test_b_spline.cpp
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Unit tests for B spline
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "spline/b_spline.h"

#include "gtest/gtest.h"

TEST(BSplineTest, InitializationTest) {
  BSpline2D spline;
  spline.initialize(2);
  EXPECT_EQ(spline.get_degree(), 2);
}

TEST(BSplineTest, DegreeUpdateTest) {
  BSpline2D spline;
  spline.initialize(2);
  spline.update_degree(4);
  EXPECT_EQ(spline.get_degree(), 4);
}

TEST(BSplineTest, EvaluateEndPointsTest) {
  const int p = 3;
  const int n = 10;

  // Defining control points
  const vec_Vec2d c = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 1.0}, {3.0, 0.0}};

  // Creating B Spline object
  BSpline2D spline;
  spline.initialize(p);

  const vec_Vec2d s = spline.evaluate_spline(c, n, true);

  EXPECT_NEAR(s[0][0], c[0][0], 1e-6);
  EXPECT_NEAR(s[0][1], c[0][1], 1e-6);
  EXPECT_NEAR(s[9][0], c[3][0], 1e-6);
  EXPECT_NEAR(s[9][1], c[3][1], 1e-6);
}
