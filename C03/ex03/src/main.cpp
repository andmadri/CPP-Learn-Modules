#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"
#include "../incl/DiamondTrap.hpp"

int main()
{
  DiamondTrap Diamond("Diamond");
  Diamond.whoAmI();

  Diamond.attack("Sebas");
  return 0;
}
