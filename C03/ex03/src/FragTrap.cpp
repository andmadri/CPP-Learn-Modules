#include "../incl/FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
  m_hit_points = 100;
  m_energy_points = 100;
  m_attack_damage = 30;
  std::cout << "FragTrap " << name << " is created" << std::endl;
}

FragTrap::FragTrap(FragTrap& other): ClapTrap(other)
{
  std::cout << "FragTrap " << m_name << " copied from " << other.m_name<< std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(FragTrap& other)
{
  if (this != &other){
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << m_name << " assigned from " << other.m_name<< std::endl;
  }
  return *this;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTRap " << m_name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
  std::cout << "FragTrap " << m_name << " requests a HighFive!" << std::endl;
}
