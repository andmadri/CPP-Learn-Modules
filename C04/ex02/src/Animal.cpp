#include "../incl/Animal.hpp"

Animal::Animal(){
    std::cout << "Animal created" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const{
    return type;
}