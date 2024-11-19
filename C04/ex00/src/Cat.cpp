#include "../incl/Cat.hpp"

Cat::Cat(): Animal(){
    this->type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other){
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other){
       Animal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
