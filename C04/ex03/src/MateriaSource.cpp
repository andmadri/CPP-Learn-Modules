#include "../incl/MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; ++i){
        m_materias[i] = nullptr;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other){
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
    if (this != &other){
        for (int i = 0; i < 4; ++i){
            delete m_materias[i];
            if (other.m_materias[i]){
                m_materias[i] = other.m_materias[i] ->clone();
            }
            else{
                m_materias[i] = nullptr;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; ++i){
        delete m_materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m ){
    for (int i = 0; i < 4; ++i){
        if (!m_materias[i]){
            m_materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; ++i){
        if (m_materias[i]->getType() == type)
            return m_materias[i];
    }
    return nullptr;
}
