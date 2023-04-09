/**
 * @file bezier_spline_test.cpp
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Unit tests for Bezier spline
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "spline/bezier_spline.h"

#include "gtest/gtest.h"

TEST(BezierSplineTest, InitializationTest) {
  BezierSpline2D spline;
  spline.initialize(2);
  EXPECT_EQ(spline.get_degree(), 2);
}

TEST(BezierSplineTest, EvaluateEndPointsTest) {
  const int n = 10;
  // Defining control points
  const vec_Vec2d c = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 1.0}, {3.0, 0.0}};

  // Creating Bezier Spline object
  BezierSpline2D spline;

  const vec_Vec2d s = spline.evaluate_spline(c, n, true);

  EXPECT_NEAR(s[0][0], c[0][0], 1e-6);
  EXPECT_NEAR(s[0][1], c[0][1], 1e-6);
  EXPECT_NEAR(s[9][0], c[3][0], 1e-6);
  EXPECT_NEAR(s[9][1], c[3][1], 1e-6);
}