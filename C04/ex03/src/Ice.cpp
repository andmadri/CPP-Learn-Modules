#include "../incl/Ice.hpp"

Ice::Ice(): AMateria("ice"){
}

Ice::Ice(const Ice& other): AMateria("ice"){
    *this = other;
}

Ice& Ice::operator=(const Ice& other){
    if (this != &other){
        AMateria::operator=(other);
        //copy other members but not m_type;
    }
    return *this;
}

AMateria* clone() const override{
    return new Ice(*this);
}

void Ice::use(ICharacter& target) override{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}
