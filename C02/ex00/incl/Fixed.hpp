#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:

  int fpnum_value;
  static const int frac_bits {8};

};

#endif