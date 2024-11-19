#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"

int main(){
  // const Animal* meta = new Animal();
  // const Animal meta;
  const Animal* j = new Dog();
  const Animal* i = new Cat();


  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();

  delete j;
  delete i;
}
