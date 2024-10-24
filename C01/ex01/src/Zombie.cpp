#include "../incl/Zombie.hpp"

void  Zombie::announce(void){
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(const std::string& name): name{name}{
}

Zombie::~Zombie(){
  std::cout << this->name << " is destroyed\n";
}
