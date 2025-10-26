#ifndef BEE_H
#define BEE_H

#include <concepts>

namespace bee {

/**
 * Floating point type.
 */
template <typename T>
  requires std::floating_point<T>
class FloatingPoint {
public:
  /**
   * Constructor.
   */
  constexpr explicit FloatingPoint(T value) : value_(value) {}

  /**
   * Gets the value.
   */
  constexpr T value() const { return value_; }

  /**
   * Performs the unary - operation.
   */
  constexpr FloatingPoint operator-() const { return FloatingPoint(-value_); }

  /**
   * Performs the + operation.
   */
  constexpr FloatingPoint operator+(const FloatingPoint &other) const {
    return FloatingPoint(value_ + other.value_);
  }

  /**
   * Performs the - operation.
   */
  constexpr FloatingPoint operator-(const FloatingPoint &other) const {
    return FloatingPoint(value_ - other.value_);
  }

  /**
   * Performs the * operation.
   */
  constexpr FloatingPoint operator*(const FloatingPoint &other) const {
    return FloatingPoint(value_ * other.value_);
  }

  /**
   * Performs the / operation.
   */
  constexpr FloatingPoint operator/(const FloatingPoint &other) const {
    return FloatingPoint(value_ / other.value_);
  }

private:
  T value_;
};

} // namespace bee

#endif