#pragma once

#include <iostream>
#include <string>
#include "../incl/Animal.hpp"
#include "../incl/Brain.hpp"

class Cat: public Animal{
public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  void makeSound() const override;

private:
  Brain* m_brain;
};
