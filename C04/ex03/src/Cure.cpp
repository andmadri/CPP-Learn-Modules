#include "../incl/Cure.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure& other): AMateria("ice"){
    *this = other;
}

Cure& Cure::operator=(const Cure& other){
    if (this != &other){
        m_type = other.m_type;
    }
    return *this;
}

AMateria* Cure::clone() const{
    return new Cure(*this);
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}