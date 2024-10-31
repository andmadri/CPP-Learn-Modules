#include "../incl/ClapTrap.hpp"
#include "../incl/ScavTrap.hpp"

int main()
{
  ClapTrap Kitsune("Kitsune");
  ScavTrap Molly("Molly");

  Kitsune.attack("Tanuki");
  Molly.attack("Sebas");

  Kitsune.takeDamage(10);
  Molly.takeDamage(100);

  Kitsune.attack("Kirin");
  Molly.attack("Sebas");

  Kitsune.beRepaired(20);
  Molly.beRepaired(25);

  Molly.guardGate();

  return 0;
}