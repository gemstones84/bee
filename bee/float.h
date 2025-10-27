#ifndef BEE_FLOAT_H
#define BEE_FLOAT_H

#include <compare>
#include <concepts>

namespace bee {

/**
 * @brief Represents a IEEE 754 floating point number.
 */
template <typename T>
  requires std::floating_point<T>
class FloatingPoint {
public:
  /**
   * @brief Constructs a new value.
   */
  constexpr explicit FloatingPoint(T value) : value_(value) {}

  /**
   * @brief Gets the value.
   */
  constexpr T value() const { return value_; }

  /**
   * @brief Returns the negative of this value.
   */
  constexpr FloatingPoint operator-() const { return FloatingPoint(-value_); }

  /**
   * @brief Adds the other value to this value.
   */
  constexpr FloatingPoint operator+(const FloatingPoint &other) const {
    return FloatingPoint(value_ + other.value_);
  }

  /**
   * @brief Subtracts the other value from this value.
   */
  constexpr FloatingPoint operator-(const FloatingPoint &other) const {
    return FloatingPoint(value_ - other.value_);
  }

  /**
   * @brief Multiplies this value by the other value.
   */
  constexpr FloatingPoint operator*(const FloatingPoint &other) const {
    return FloatingPoint(value_ * other.value_);
  }

  /**
   * @brief Divides this value by the other value.
   */
  constexpr FloatingPoint operator/(const FloatingPoint &other) const {
    return FloatingPoint(value_ / other.value_);
  }

  /**
   * @brief Compares this value with the specified value for order.
   */
  constexpr auto operator<=>(const FloatingPoint<T> &other) const = default;

private:
  T value_;
};

} // namespace bee

#endif