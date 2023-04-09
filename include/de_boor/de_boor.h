/**
 * @file de_boor.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Main implementation of De Boor's algorithm
 * @version 0.1
 * @date 2023-03-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DE_BOOR_H
#define DE_BOOR_H

#include <assert.h>

#include <algorithm>
#include <tuple>

#include "basis/data_type.h"
#include "basis/data_utils.h"

template <int Dim>
struct DeBoor {
  DeBoor() = default;

  /**
   * @brief Generate knot vector which is defined with spline degree
   * and number of control points
   */
  void generate_knot_vector() {
    // Control points size
    const int m = static_cast<int>(c_.size());
    // If number of control points is less than degree of spline terminate
    // program
    assert(m < p_ - 1);
    const int v_size = m - p_ + 1;
    // Increasing multiplicity of first and last node should be p + 1
    u_ = merge_vectors<decimal_t>(
        generate_vector_of_values<decimal_t>(p_, 0.0),
        generate_linspace<decimal_t>(0.0, 1.0, v_size, true),
        generate_vector_of_values<decimal_t>(p_, 1.0));
  }

  /**
   * @brief Computes index of knot interval that contains given position and
   * multiplicity of the position
   * @param x Position
   */
  std::tuple<size_t, int> find_knot_index_by_value(const decimal_t& x) const {
    assert(x < u_.front() || x > u_.back());

    int s = 0;
    size_t i = 0;

    while (i < u_.size() && u_[i] <= x) {
      if (u_[i] == x) {
        s++;
      }
      i++;
    }

    return std::make_tuple(i - 1, s);
  }

  /**
   * @brief Evaluates spline curve at position x
   * @param x Position
   */
  Vecd<Dim> operator()(const decimal_t& x) const {
    int k, s;
    std::tie(k, s) = find_knot_index_by_value(x);

    // Inserting x enough times so that x becomes knot of multiplicity p
    const auto h = p_ - s;

    // If x is knot of multiplicity greater than degree of spline,
    // return coresponding control point
    if (h <= 0) {
      return c_[std::clamp(k - p_ - 1, 0, static_cast<int>(c_.size()) - 1)];
    }

    // Copying affected control points
    vec_Vecd<Dim> d = {c_.begin() + k - p_, c_.begin() + k - p_ + h + 1};

    // Inserting x h number of times
    for (int r = 1; r <= h; r++) {
      for (int j = h; j >= r; j--) {
        const auto a =
            (x - u_[j + k - h]) / (u_[j + 1 + k - r] - u_[j + k - h]);
        d[j] = (1.0 - a) * d[j - 1] + a * d[j];
      }
    }

    return d[h];
  }

  /**
   * @brief Update degree of spline
   * @param p Degree of spline
   */
  inline void update_degree(const int& p) { p_ = p; }

  /**
   * @brief Getter for degree of spline
   */
  inline int get_degree() const { return p_; }

  /**
   * @brief Update control points
   * @param c Control points
   */
  inline void update_control_points(const vec_Vecd<Dim>& c) { c_ = c; }

  /**
   * @brief Getter for control points
   */
  inline vec_Vecd<Dim> get_control_points() const { return c_; }

  /**
   * @brief Getter for knot vector
   */
  inline vec_d get_knot_vector() const { return u_; }

  // degree of spline
  int p_;
  // control points
  vec_Vecd<Dim> c_;
  // knot vector
  vec_d u_;
};

typedef DeBoor<2> DeBoor2D;

typedef DeBoor<3> DeBoor3D;

#endif