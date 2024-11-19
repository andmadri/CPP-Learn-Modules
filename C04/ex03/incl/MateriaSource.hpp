#pragma once

#include <iostream>
#include <string>
#include "../incl/IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* m) override;
    AMateria* createMateria(std::string const & type) override;

private:
    AMateria* m_materias[4];
};