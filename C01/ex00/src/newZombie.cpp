#include "../incl/Zombie.hpp"

Zombie* Zombie::newZombie(std::string name){
  Zombie* new_zombie = new (std::nothrow) Zombie(name);
  if (new_zombie){
    return new_zombie;
  }
  std::cerr << "Memory Allocation Failed\n";
  return nullptr;
}