#include "../incl/Zombie.hpp"

void  Zombie::randomChump(std::string name){
  Zombie stack_zombie(name);
  stack_zombie.announce();
}
