#pragma once

#include <iostream>
#include <string>

class WrongAnimal{
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal& operator=(const WrongAnimal &other);
  virtual ~WrongAnimal() = default;

  void makeSound() const;
  virtual std::string getType() const;

protected:
  std::string type;

};

