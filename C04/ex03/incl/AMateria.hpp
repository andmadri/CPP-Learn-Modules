#pragma once

#include <iostream>
#include <string>
#include "../incl/ICharacter.hpp"

class ICharacter;

class AMateria{
protected:
  std::string m_type;

public:
  AMateria(std::string const & type);
  virtual ~AMateria() = default;
  std::string const & getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

};
