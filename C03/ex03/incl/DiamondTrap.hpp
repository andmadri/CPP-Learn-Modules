#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{

public:
    DiamondTrap(std::string name);
    DiamondTrap& DiamondTrap(DiamondTrap& other);


    void whoAmI();


private:
    std::string m_name;
};

#endif