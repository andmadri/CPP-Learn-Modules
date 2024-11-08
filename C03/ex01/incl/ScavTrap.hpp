#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../incl/ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap{

public:

  ScavTrap() = default;
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  ~ScavTrap();

  void guardGate();
  void attack(const std::string& target) override;

};

#endif