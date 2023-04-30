/**
 * @file data_type.h
 * @author Borna Zbodulja (borna.zbodulja@gmail.com)
 * @brief Defines all data types used in the library
 * @version 0.1
 * @date 2023-03-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <Eigen/Geometry>
#include <Eigen/StdVector>
#include <vector>

typedef double decimal_t;

/// Pre-allocated std::vector for Eigen using vec_E
template <typename T>
using vec_T = std::vector<T, Eigen::aligned_allocator<T>>;
// Eigen 1D double vector
template <int N>
using Vecd = Eigen::Matrix<decimal_t, N, 1>;
// Vector of Eigen 1D double vector
template <int N>
using vec_Vecd = vec_T<Vecd<N>>;
// Vector of scalars
using vec_d = vec_T<decimal_t>;

// Eigen 1D double vector of size 2
typedef Vecd<2> Vec2d;
// Eigen 2D double vector of size 3
typedef Vecd<3> Vec3d;
// Vector of Eigen 1D vector of size 2
typedef vec_Vecd<2> vec_Vec2d;
// Vector of Eigen 1D vector of size 3
typedef vec_Vecd<3> vec_Vec3d;

#endif