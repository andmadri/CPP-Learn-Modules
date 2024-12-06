#pragma once

#include <iostream>
#include <string>
#include "../incl/AMateria.hpp"

class Cure: public AMateria{
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure() = default;

    AMateria* clone() const override;
    void use(ICharacter& traget) override;
};
