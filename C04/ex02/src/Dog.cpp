#include "../incl/Dog.hpp"

Dog::Dog(): Animal(), m_brain(new Brain()){
  this->type = "Dog";
  std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other){
  *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
  if (this != &other){
    Animal::operator=(other);
    delete this->m_brain;
    this->m_brain = new Brain(*other.m_brain);
  }
  std::cout << "Dog::operator= used" << std::endl; 
  return *this;
}

Dog::~Dog(){
  std::cout << "Dog destroyed" << std::endl;
  delete this->m_brain;
}

void Dog::makeSound() const{
  std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const{
  return this->m_brain;
}
