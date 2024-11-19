#include "../incl/Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other){
    *this = other;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other){
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const{
    return type;
}