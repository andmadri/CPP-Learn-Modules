#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    this->type = "WrongCat";
    std::cout << "WrongCat is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other){
       WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
