#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

public:
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap& other);
  DiamondTrap& operator=(DiamondTrap &other);
  ~DiamondTrap();

  void attack(const std::string& target);
  void whoAmI();

private:
  std::string m_name;
};

#endif