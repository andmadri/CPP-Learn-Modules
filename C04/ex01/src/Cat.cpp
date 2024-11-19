#include "../incl/Cat.hpp"

Cat::Cat(): Animal(), m_brain(new Brain()){
  this->type = "Cat";
  std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
  *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
  if (this != &other){
    Animal::operator=(other);
    delete this->m_brain;
    this->m_brain = new Brain(*other.m_brain);
  }
  return *this;
}

Cat::~Cat(){
  std::cout << "Cat destroyed" << std::endl;
  delete this->m_brain;
}

void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
