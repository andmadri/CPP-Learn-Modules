#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
  std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other): ClapTrap(other)
{
  std::cout << "ScavTrap " << this->getName() << " copied from " << other.getName() << std::endl;
  *this = other;
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
  if (this != &other){
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << this->getName() << " assigned from " << other.getName() << std::endl;
  }
  return *this;
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
  if(this->getEnergyPoints() <= 0 || this->getHitPoints() <= 0){
     std::cout << "ScavTrap " << this->getName() << " has no energy/hit points left" << std::endl;
     return ;
  }
  this->setEnergyPoints(-1);
  std::cout << "ScavTrap " << this->getName() << " attacks " << target;
  std::cout << " causing " << this->getAttackDamage() << " points of damage\n";
}
