#include "../incl/ScavTrap.hpp"

// ScavTrap::ScavTrap(const std::string& name)
// : ClapTrap(name)
// {
//     std::cout << "ScavTrap " << name << "is created\n";
// }

 ScavTrap::ScavTrap(ScavTrap& other): ClapTrap(other)
 {
    std::cout << "ScavTrap " << this->getName() << " copied from " << other.getName() << std::endl;
    *this = other;
 }

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << this->getName() << " assigned from " << other.getName() << std::endl;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " is in Gate keeper mode\n";
}

void attack(const std::string& target)
{
    ClapTrap::attack(target);
}