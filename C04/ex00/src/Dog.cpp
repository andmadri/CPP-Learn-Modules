#include "../incl/Dog.hpp"

Dog::Dog(): Animal(){
    this->type = "Dog";
}

Dog::Dog(const Dog& other): Animal(other){
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other){
       Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Woof" << std::endl;
}
