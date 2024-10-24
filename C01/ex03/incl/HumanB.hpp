#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../incl/Weapon.hpp"
#include <iostream>
#include <sstream>
#include <string>

class HumanB{

public:

    HumanB(const std::string& name);
    ~HumanB() = default;
    void setWeapon(Weapon& type);
    void attack();

private:

    std::string name;
    Weapon* weapon;
};

#endif