#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
  m_hit_points = 100;
  m_energy_points = 50;
  m_attack_damage = 20;
  std::cout << "ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
  m_hit_points = 100;
  m_energy_points = 50;
  m_attack_damage = 20;
  std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap " << m_name << " is destroyed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
  std::cout << "ScavTrap " << m_name << " copied from " << other.m_name << std::endl;
  *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
  if (this != &other)
  {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << m_name << " assigned from " << other.m_name << std::endl;
  }
  return *this;
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << m_name << " is in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
  if (m_energy_points <= 0 || m_hit_points <= 0)
  {
    std::cout << "ScavTrap " << m_name << " has no energy/hit points left" << std::endl;
    return;
  }
  m_energy_points--;
  std::cout << "ScavTrap " << m_name << " attacks " << target;
  std::cout << " causing " << m_attack_damage << " points of damage\n";
}
