#pragma once

#include <iostream>
#include <string>
#include "../incl/WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
public:
  WrongCat();
  WrongCat(const WrongCat& other);
  WrongCat& operator=(const WrongCat& other);
  virtual ~WrongCat() = default;

  void makeSound() const;
};
