#pragma once

#include <iostream>
#include <string>

class Animal{
public:
  Animal();
  Animal(const Animal &other);
  Animal& operator=(const Animal &other);
  virtual ~Animal();

  virtual void makeSound() const;
  virtual std::string getType() const;

protected:
  std::string type;

};
