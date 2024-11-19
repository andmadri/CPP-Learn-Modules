#pragma once

#include <iostream>
#include <string>
#include "../incl/AMateria.hpp"

class Ice: public AMateria{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria* clone() const override;
    void use(ICharacter& traget) override;
};
