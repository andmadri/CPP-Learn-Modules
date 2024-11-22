#include "../incl/Animal.hpp"
#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"

void testDeepCopy(){
  Dog originalDog;
  originalDog.getBrain()->m_ideas[0] = "Original Dog Idea\n";
  Dog copiedDog = originalDog;
  copiedDog.getBrain()->m_ideas[0] = "Copied Dog Idea\n";
  std::cout << "Original Dog: " << originalDog.getBrain()->m_ideas[0];
  std::cout << "Copy Dog: " << copiedDog.getBrain()->m_ideas[0];

}

int main(){
  const int size = 10;
  Animal* animals[size];

  for (int i = 0; i < size; ++i){
    if (i < size / 2){
      std::cout << i << ": ";
      animals[i] = new Dog();
    }
    else{
      std::cout << i << ": ";
      animals[i] = new Cat();
    }
  }

  std::cout << "\n\n";
  for (int i = 0; i < size; ++i){
    delete animals[i];
  }
  testDeepCopy();
}
