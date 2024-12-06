#include "../incl/Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "Animal is created" << std::endl;
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
    std::cout << "Animal is destroyed" << std::endl;
}


void Animal::makeSound() const{
    std::cout << "[Animal Sound]" << std::endl;
}

std::string Animal::getType() const{
    return type;
}