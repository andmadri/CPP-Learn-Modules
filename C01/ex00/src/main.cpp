#include "../incl/Zombie.hpp"

int main(){
    Zombie zombie("Foo");
    zombie.announce();

    Zombie* heap_zombie = Zombie::newZombie("HeapFoo");
    if (heap_zombie){
        heap_zombie->announce();
        delete heap_zombie;
    }
    Zombie::randomChump("StackFoo");
    return 0;
}
