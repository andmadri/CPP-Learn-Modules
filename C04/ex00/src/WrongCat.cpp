#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    this->type = "WrongCat";
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

void WrongCat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
