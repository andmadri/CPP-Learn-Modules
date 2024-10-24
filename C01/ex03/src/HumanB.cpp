#include "../incl/HumanB.hpp"

HumanB::HumanB(const std::string& name)
: name(name), weapon(nullptr){}

void HumanB::attack(){
    if(weapon){
        std::stringstream ss;
        ss << this->name << " attacks with their ";
        ss << this->weapon->getType();
        std::cout << ss.str() << std::endl;
        return ;
    }
    std::cout << this->name << "does not have a weapon\n";
}

void HumanB::setWeapon(Weapon& type){
    weapon = &type;
}
