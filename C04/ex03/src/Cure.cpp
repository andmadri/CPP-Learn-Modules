#include "../incl/Cure.hpp"

Cure::Cure(): AMateria("cure"){
}

Cure::Cure(const Cure& other): AMateria("ice"){
    *this = other;
}

Cure& Cure::operator=(const Cure& other){
    if (this != &other){
        AMateria::operator=(other);
        //copy other members but not m_type;
    }
    return *this;
}

AMateria* clone() const override{
    return new Cure(*this);
}

void Cure::use(ICharacter& target) override{
    std::cout << "* heals " << target.getName() << "'s wounds *";
}