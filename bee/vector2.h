#ifndef BEE_VECTOR2_H
#define BEE_VECTOR2_H

#include "float.h"
#include <concepts>

namespace bee {

/**
 * @brief Representation of 2D vectors and points.
 */
template <typename T>
  requires std::floating_point<T>
class Vector2 {
public:
  /**
   * @brief Constructs a new vector with given x, y components.
   */
  constexpr explicit Vector2(const FloatingPoint<T> &x,
                             const FloatingPoint<T> &y)
      : x_(x), y_(y) {}

  /**
   * @brief Gets the X component of the vector.
   */
  constexpr FloatingPoint<T> x() const { return x_; }

  /**
   * @brief Gets the Y component of the vector.
   */
  constexpr FloatingPoint<T> y() const { return y_; }

  /**
   * @brief Returns the negative of this vector.
   */
  constexpr Vector2 operator-() const { return Vector2(-x_, -y_); }

  /**
   * @brief Adds the other vector to this vector.
   */
  constexpr Vector2 operator+(const Vector2 &other) const {
    return Vector2(x_ + other.x_, y_ + other.y_);
  }

  /**
   * @brief Subtracts the other vector from this vector.
   */
  constexpr Vector2 operator-(const Vector2 &other) const {
    return Vector2(x_ - other.x_, y_ - other.y_);
  }

  /**
   * @brief Multiplies a vector by a number.
   */
  friend constexpr Vector2 operator*(const Vector2 &a,
                                     const FloatingPoint<T> &d) {
    return Vector2(a.x_ * d, a.y_ * d);
  }

  /**
   * @brief Divides a vector by a number.
   */
  friend constexpr Vector2 operator/(const Vector2 &a,
                                     const FloatingPoint<T> &d) {
    return Vector2(a.x_ / d, a.y_ / d);
  }

  /**
   * @brief Returns true if two vectors are approximately equal.
   */
  constexpr bool operator==(const Vector2 &other) const = default;

  /**
   * @brief Shorthand for writing Vector2(0, 0).
   */
  static constexpr Vector2 zero() {
    return Vector2(FloatingPoint<T>(T()), FloatingPoint<T>(T()));
  }

private:
  FloatingPoint<T> x_;
  FloatingPoint<T> y_;
};

} // namespace bee

#endif