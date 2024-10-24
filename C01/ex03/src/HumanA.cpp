#include "../incl/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& type)
: name(name), weapon(type)
{
}

void HumanA::attack(){
    std::stringstream ss;

    ss << this->name << " attacks with their ";
    ss << this->weapon.getType();
    std::cout << ss.str() << std::endl;
}
