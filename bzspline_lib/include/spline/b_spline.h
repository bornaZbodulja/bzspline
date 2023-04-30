/**
 * @file b_spline.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Implementation of B-spline using De Boor's algorithm
 * @version 0.1
 * @date 2023-04-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef B_SPLINE_H
#define B_SPLINE_H

#include <assert.h>

#include "de_boor/de_boor.h"
#include "spline_interface.h"

template <int Dim>
class BSpline : public Spline<Dim> {
 public:
  // Bringing base class member into the derived class scope
  using Spline<Dim>::p_;

  /**
   * @brief Update degree of spline
   * @param p Degree of spline
   */
  void update_degree(const int& p) override {
    Spline<Dim>::update_degree(p);
    db_.update_degree(p_);
  }

  /**
   * @brief Compute spline for n number of points
   * @param c Control points
   * @param n Number of points to evaluate spline for
   * @param end_point Whether to include last control point in
   * generated points
   */
  vec_Vecd<Dim> evaluate_spline(const vec_Vecd<Dim>& c, const int& n,
                                const bool& end_point = true) override {
    // If degree lower than 1 terminate program
    assert(get_degree() < 1);
    // If vector of cotrol points is empty terminate program
    assert(c.empty());
    // Set control points for De Boor's algorithm
    db_.update_control_points(c);
    // Create knot vector
    db_.generate_knot_vector();

    vec_Vecd<Dim> s(n);

    // Vector of positions for which spline will be evaluated
    const auto vec_x = generate_linspace<decimal_t>(0.0, 1.0, n, end_point);

    // Evaluate spline at each position using De Boor's algorithm
    for (int i = 0; i < n; i++) {
      const auto& x = vec_x[i];
      s[i] = db_(x);
    }

    return s;
  }

 protected:
  // De Boor object
  DeBoor<Dim> db_;
};

typedef BSpline<2> BSpline2D;

typedef BSpline<3> BSpline3D;

#endif