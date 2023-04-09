/**
 * @file spline_interface.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Main spline interface
 * @version 0.1
 * @date 2023-04-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SPLINE_INTERFACE_H
#define SPLINE_INTERFACE_H

#include "basis/data_type.h"
#include "basis/data_utils.h"

template <int Dim>
class Spline {
 public:
  /**
   * @brief Construct a new Spline object
   */
  Spline() = default;

  /**
   * @brief Initialize spline
   * @param p Degree of spline
   */
  virtual void initialize(const int& p) { update_degree(p); };

  /**
   * @brief Update degree of spline
   * @param p Degree of spline
   */
  virtual void update_degree(const int& p) { p_ = p; }

  /**
   * @brief Returns degree of spline
   */
  inline int get_degree() const { return p_; }

  /**
   * @brief Compute spline for n number of points
   * @param c Control points
   * @param n Number of points to evaluate spline for
   * @param end_point Whether to include last control point in
   * generated points
   */
  virtual vec_Vecd<Dim> evaluate_spline(const vec_Vecd<Dim>& c, const int& n,
                                        const bool& end_point = true) = 0;

 protected:
  // degree of spline
  int p_;
};

#endif