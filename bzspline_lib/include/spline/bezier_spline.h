/**
 * @file bezier_spline.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Implementation of Bezier spline
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BEZIER_SPLINE_H
#define BEZIER_SPLINE_H

#include <assert.h>

#include <cmath>

#include "spline_interface.h"

template <int Dim>
class BezierSpline : public Spline<Dim> {
 public:
  // Bringing base class member into the derived class scope
  using Spline<Dim>::p_;

  vec_Vecd<Dim> evaluate_spline(const vec_Vecd<Dim>& c, const int& n,
                                const bool& end_point = true) override {
    const auto p = static_cast<int>(c.size()) - 1;
    // If vector of control points has less than 2 points terminate program
    assert(p < 1);
    // Degree of Bezier curve is determined by number of control points
    Spline<Dim>::update_degree(p);
    // Update control points
    update_control_points(c);
    // Precomputing binomial coefficients
    precompute_binomial_coefficients();

    vec_Vecd<Dim> s(n);

    // Vector of positions for which spline will be evaluated
    const auto vec_x = generate_linspace<decimal_t>(0.0, 1.0, n, end_point);

    // Evaluate spline at each position
    for (int i = 0; i < n; i++) {
      const auto& x = vec_x[i];
      s[i] = (*this)(x);
    }

    return s;
  }

 private:
  /**
   * @brief Update control points
   * @param c Control points
   */
  inline void update_control_points(const vec_Vecd<Dim>& c) { c_ = c; }

  /**
   * @brief Precomputes binomial coefficients based on number of control points
   * @param n Number of control points
   */
  void precompute_binomial_coefficients() {
    // If degree of spline less than 1 terminating program
    assert(p_ < 1);
    b_.resize(p_);

    for (int i = 0; i <= p_; i++) {
      b_[i] = static_cast<decimal_t>(binomial(p_, i));
    }
  }

  /**
   * @brief Evaluates Bezier curve at position x
   * @param x Position
   * @param c Control points
   */
  Vecd<Dim> operator()(const decimal_t& x) const {
    assert(x < 0.0 || x > 1.0);

    Vecd<Dim> r = Vecd<Dim>::Zero();

    for (int i = 0; i <= p_; i++) {
      r += (b_[i] * std::pow(x, i) * std::pow(1.0 - x, p_ - i)) * c_[i];
    }

    return r;
  }

 protected:
  // Binomial coefficients
  vec_d b_;
  // Control points
  vec_Vecd<Dim> c_;
};

typedef BezierSpline<2> BezierSpline2D;

typedef BezierSpline<3> BezierSpline3D;

#endif