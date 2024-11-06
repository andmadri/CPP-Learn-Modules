#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"
#include "../incl/FragTrap.hpp"

int main()
{
  ClapTrap Kitsune("Kitsune");
  FragTrap Ron("Ron");
  
  Kitsune.attack("Tanuki");
  Ron.attack("me");
  Kitsune.takeDamage(100);
  Kitsune.takeDamage(2147483647);

  Ron.takeDamage(100);

  Kitsune.attack("Kirin");
  Ron.attack("you");

  Kitsune.beRepaired(20);

  Ron.highFivesGuys();
  return 0;
}
