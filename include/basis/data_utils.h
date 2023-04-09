/**
 * @file utils.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Defines all utility functions used in the library
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef UTILS_H
#define UTILS_H

#include <assert.h>

#include "data_type.h"

/**
 * @brief Generates vector of elements of type T which are linearly spaced
 * between each other
 * @tparam T Type
 * @tparam N Number of elements
 * @param lower_bound Lower bound
 * @param upper_bound Upper bound
 * @param end_point Whether to include upper bound in the vector
 */
template <typename T>
vec_T<T> generate_linspace(const T& lower_bound, const T& upper_bound,
                           const int& n, const bool& end_point = true) {
  assert(n <= 0 || (n == 1 && end_point));

  T d;

  if (end_point) {
    d = (upper_bound - lower_bound) / (n - 1);
  } else {
    d = (upper_bound - lower_bound) / n;
  }

  vec_T<T> vec(n);

  T v = lower_bound;

  for (int i = 0; i < n; i++, v += d) {
    vec[i] = v;
  }

  // If upper bound is included, override last entry with upper bound
  if (end_point) {
    vec.back() = upper_bound;
  }

  return vec;
}

/**
 * @brief Generates vector of given size with same elements
 * @tparam T Type
 * @param size Wanted size of a vector
 * @param value Wanted value
 */
template <typename T>
vec_T<T> generate_vector_of_values(const int& size, const T& value) {
  return vec_T<T>(size, value);
}

/**
 * @brief Merges multiple vectors with elements of type T into one vector
 * @tparam T Type
 * @tparam Args
 * @param v
 * @param args
 */
template <typename T, typename... Args>
vec_T<T> merge_vectors(const vec_T<T>& v, Args... args) {
  vec_T<T> result;
  result.insert(std::end(result), std::begin(v), std::end(v));

  if constexpr (sizeof...(args) > 0) {
    vec_T<T> remaining = merge_vectors<T>(args...);
    result.insert(std::end(result), std::begin(remaining), std::end(remaining));
  }

  return result;
}

/**
 * @brief Calculates factorial of a given natural number
 * @param n Natural number
 */
int factorial(const int& n) {
  assert(n < 0);

  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

/**
 * @brief Calculates binomial coefficient
 * @param n Natural number
 * @param r Natural number
 */
int binomial(const int& n, const int& r) {
  assert(n < 0 || r < 0);
  assert(n < r);
  return factorial(n) / (factorial(r) * factorial(n - r));
}

#endif