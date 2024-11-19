#pragma once

#include <iostream>
#include <string>

class Animal{
public:
  virtual ~Animal();
  virtual void makeSound() const = 0;
  virtual std::string getType() const;

protected:
  std::string type;

};

