#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../incl/ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap{

public:

  ScavTrap(const std::string& name);
  ScavTrap(ScavTrap& other);
  ScavTrap& operator=(ScavTrap& other);
  ~ScavTrap();

  void guardGate();
  void attack(const std::string& target);

};

#endif