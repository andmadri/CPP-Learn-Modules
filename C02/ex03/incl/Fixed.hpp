#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:
  Fixed();
  Fixed(const int integer);
  Fixed(const float floating_point);
  Fixed(const Fixed& other);
  ~Fixed() = default;

  float toFloat(void) const;
  int toInt(void) const;

  Fixed& operator=(const Fixed& other);
  Fixed operator+(const Fixed& other);
  Fixed operator-(const Fixed& other);
  Fixed operator*(const Fixed& other);
  Fixed operator/(const Fixed& other);

  bool operator<(const Fixed& other) const;
  bool operator>(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& min(Fixed& num1, Fixed& num2);
  static const Fixed& min(const Fixed& num1, const Fixed& num2);
  static Fixed& max(Fixed& num1, Fixed& num2);
  static const Fixed& max(const Fixed& num1, const Fixed& num2);

  int getRawBits(void) const;

private:

  int fpnum_value;
  static const int frac_bits {8};

};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif