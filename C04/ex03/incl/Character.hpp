#pragma once

#include <iostream>
#include <string>
#include "../incl/ICharacter.hpp"

class Character: public ICharacter{
public:
    Character();
    Character(const std::string& name);
    Character(const Character& other); //deep copy
    Character& operator=(const Character& other); //deep copy
    ~Character();

private:
    std::string m_name;
    AMateria* m_inventory[4];
};
