#ifndef BEE_VECTOR3_H
#define BEE_VECTOR3_H

#include "float.h"
#include <concepts>

namespace bee {

/**
 * @brief Representation of 3D vectors and points.
 */
template <typename T>
  requires std::floating_point<T>
class Vector3 {
public:
  /**
   * @brief Creates a new three-dimensional vector or point.
   */
  constexpr explicit Vector3(const FloatingPoint<T> &x,
                             const FloatingPoint<T> &y,
                             const FloatingPoint<T> &z)
      : x_(x), y_(y), z_(z) {}

  /**
   * @brief Gets the X component of the vector.
   */
  constexpr FloatingPoint<T> x() const { return x_; }

  /**
   * @brief Gets the Y component of the vector.
   */
  constexpr FloatingPoint<T> y() const { return y_; }

  /**
   * @brief Gets the Z component of the vector.
   */
  constexpr FloatingPoint<T> z() const { return z_; }

  /**
   * @brief Returns the negative of this vector.
   */
  constexpr Vector3 operator-() const { return Vector3(-x_, -y_, -z_); }

  /**
   * @brief Adds the other vector to this vector.
   */
  constexpr Vector3 operator+(const Vector3 &other) const {
    return Vector3(x_ + other.x_, y_ + other.y_, z_ + other.z_);
  }

  /**
   * @brief Subtracts the other vector from this vector.
   */
  constexpr Vector3 operator-(const Vector3 &other) const {
    return Vector3(x_ - other.x_, y_ - other.y_, z_ - other.z_);
  }

  /**
   * @brief Multiplies a vector by a number.
   */
  friend constexpr Vector3 operator*(const Vector3 &a,
                                     const FloatingPoint<T> &d) {
    return Vector3(a.x_ * d, a.y_ * d, a.z_ * d);
  }

  /**
   * @brief Divides a vector by a number.
   */
  friend constexpr Vector3 operator/(const Vector3 &a,
                                     const FloatingPoint<T> &d) {
    return Vector3(a.x_ / d, a.y_ / d, a.z_ / d);
  }

  /**
   * @brief Returns true if two vectors are approximately equal.
   */
  constexpr bool operator==(const Vector3 &other) const = default;

  /**
   * @brief Shorthand for writing Vector3(0, 0, 0).
   */
  static constexpr Vector3 zero() {
    return Vector3(FloatingPoint<T>(T()), FloatingPoint<T>(T()),
                   FloatingPoint<T>(T()));
  }

private:
  FloatingPoint<T> x_;
  FloatingPoint<T> y_;
  FloatingPoint<T> z_;
};

} // namespace bee

#endif