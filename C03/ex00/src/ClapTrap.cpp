#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
: m_name(name), m_hit_points(10), m_energy_points(10),
  m_attack_damage(0) 
  {
    std::cout << name << " is created\n";
  }

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << this->m_name << " is being created";
    std::cout << " using the values of " << other.m_name << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other){
        this->m_name = other.m_name;
        this->m_hit_points = other.m_hit_points;
        this->m_energy_points = other.m_energy_points;
        this->m_attack_damage = other.m_attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (m_energy_points <= 0 || m_hit_points <= 0){
        std::cout << "ClapTrap " << m_name << " has no more energy/hit_points left\n";
        return;
    }
    --m_energy_points;
    std::cout << "ClapTrap " << m_name << " attacks " << target;
    std::cout << " causing " << m_hit_points << " points of damage\n";

}

void ClapTrap::takeDamage(unsigned int amount)
{
    m_hit_points -= amount;
    std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage!";
    std::cout << " Remaining hit points: " << m_hit_points << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_energy_points <= 0){
        std::cout << "ClapTrap " << m_name << " has no more energy/hit_points left\n";
        return;
    }
    m_hit_points += amount;
    --m_energy_points;
    std::cout << "ClapTrap " << m_name << " hit points are now ";
    std::cout << amount << " more than before\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << m_name << " is destroyd\n";
}
