#pragma once

#include <iostream>
#include <string>
#include "../incl/ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();

    std::string const &getName() const override;
    void equip(AMateria *m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter &target) override;

private : 
    std::string m_name;
    AMateria *m_inventory[4];
    AMateria *m_dscrd_inventory[4];
};
