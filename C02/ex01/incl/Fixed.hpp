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
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  float toFloat(void) const;
  int toInt(void) const;

private:

  int fpnum_value;
  static const int frac_bits {8};

};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif