#pragma once

#include <iostream>
#include <string>
#include "../incl/Animal.hpp"
#include "../incl/Brain.hpp"

class Dog: public Animal{
public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog();

  void makeSound() const override;
  Brain* getBrain() const;

private:
  Brain* m_brain;
};
