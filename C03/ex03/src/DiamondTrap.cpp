#include "../incl/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
		: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name),
			m_name(name)
{
	m_hit_points = FragTrap::m_hit_points;
	m_energy_points = ScavTrap::m_energy_points;
	m_attack_damage = FragTrap::m_attack_damage;
	std::cout << "DiamondTrap " << m_name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
		: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->m_name = other.m_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << m_name << " is destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: I am " << this->m_name << std::endl;
	std::cout << "DiamondTrap::ClapTrap: I am " << ClapTrap::m_name << std::endl;
}
