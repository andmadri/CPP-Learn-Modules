#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../incl/Weapon.hpp"
#include <iostream>
#include <sstream>
#include <string>

class HumanA{

public:

    HumanA(const std::string& name, Weapon& type);
    ~HumanA() = default;
    void attack();

private:

    std::string name;
    Weapon& weapon;
};

#endif
