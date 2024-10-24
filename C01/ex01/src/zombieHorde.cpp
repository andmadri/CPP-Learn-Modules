#include "../incl/Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name){
  Zombie* zombie_array = new Zombie[N];
  for (int i = 0; i < N; ++i){
    zombie_array[i].name = name;
  }
  return zombie_array;
}
