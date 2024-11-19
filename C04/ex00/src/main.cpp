#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"
#include "../incl/WrongAnimal.hpp"
#include "../incl/WrongCat.hpp"

int main(){
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const WrongAnimal* meta_w = new WrongAnimal();
  const WrongAnimal* i_w = new WrongCat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << meta_w->getType() << " " << std::endl;
  std::cout << i_w->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta_w->makeSound();
  i_w->makeSound();
  meta->makeSound();


  delete meta;
  delete j;
  delete i;
  delete meta_w;
  delete i_w;
}
