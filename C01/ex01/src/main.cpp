#include "../incl/Zombie.hpp"

int main(){

    const int number_zombies = 5;
    Zombie* zombies = Zombie::zombieHorde(number_zombies, "Bob"); 
    for (int i = 0; i < number_zombies; ++i){
        zombies[i].announce();
    }
    delete[] zombies;
    return 0;
}