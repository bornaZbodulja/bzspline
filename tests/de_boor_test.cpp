/**
 * @file test_de_boor.cpp
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Test for De Boor algorithm by generating a curve and checking if
 * the points are correct
 * @version 0.1
 * @date 2023-04-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "de_boor/de_boor.h"

#include "gtest/gtest.h"

TEST(DeBoorTest, InitializationTest) {
  const int p = 3;

  DeBoor2D db;
  db.update_degree(p);
  EXPECT_EQ(db.get_degree(), p);
}

TEST(DeBoorTest, ControlPointsTest) {
  // Defining control points
  const vec_Vec2d c = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 1.0}, {3.0, 0.0}};

  DeBoor2D db;
  db.update_control_points(c);

  const auto l = db.get_control_points();

  for (size_t i = 0; i < c.size(); i++) {
    EXPECT_NEAR(c[i][0], l[i][0], 1e-6);
    EXPECT_NEAR(c[i][1], l[i][1], 1e-6);
  }
}

TEST(DeBoorTest, KnotVectorTest) {
  const int p = 2;
  // Defining control points
  const vec_Vec2d c = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 1.0}, {3.0, 0.0}};
  // Expected knot vector
  vec_d u = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0};

  DeBoor2D db;
  db.update_degree(p);
  db.update_control_points(c);
  db.generate_knot_vector();

  const auto l = db.get_knot_vector();

  for (size_t i = 0; i < u.size(); i++) {
    EXPECT_NEAR(l[i], u[i], 1e-6);
  }
}

TEST(DeBoorTest, EndPointsTest) {
  const int p = 2;
  // Defining control points
  const vec_Vec2d c = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 1.0}, {3.0, 0.0}};

  DeBoor2D db;
  db.update_degree(p);
  db.update_control_points(c);
  db.generate_knot_vector();

  EXPECT_NEAR(c[0][0], db(0.0)[0], 1e-6);
  EXPECT_NEAR(c[0][1], db(0.0)[1], 1e-6);
  EXPECT_NEAR(c[3][0], db(1.0)[0], 1e-6);
  EXPECT_NEAR(c[3][1], db(1.0)[1], 1e-6);
}
