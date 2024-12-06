#pragma once

#include <iostream>
#include <string>
#include "../incl/Animal.hpp"

class Dog: public Animal{
public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog();

  void makeSound() const override;
};
