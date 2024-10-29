#include "../incl/ClapTrap.hpp"

int main()
{
    ClapTrap Kitsune("Kitsune");

    Kitsune.attack("Tanuki");
    Kitsune.takeDamage(10);
    Kitsune.attack("Kirin");
    Kitsune.beRepaired(20);
    Kitsune.attack("Geiko");
    return 0;
}