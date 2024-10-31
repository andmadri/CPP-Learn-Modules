#include "../incl/FragTrap.hpp"

FragTrap::FragTrap(std::string& name): ClapTrap(name)
{
  std::cout << "FragTrap " << name << " is created" << std::endl;
}

FragTrap::FragTrap(FragTrap& other)
{
  std::cout << "FragTrap " << this->getName() << " copied from " << other.getName() << std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(FragTrap& other)
{
  if (this != &other){
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << this->getName() << " assigned from " << other.getName() << std::endl;
  }
  return *this;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTRap " << this->getName() << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
  std::cout << ""
}