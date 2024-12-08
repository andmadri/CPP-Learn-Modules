#pragma once

#include <iostream>
#include <string>
#include "../incl/AMateria.hpp"

class IMateriaSource{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};