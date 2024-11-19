#include "../incl/Character.hpp"

Character::Character(): m_name(""){
    for (int i = 0; i < 4; ++i){
        m_inventory[i] = nullptr;
    }
}

Character::Character(const std::string& name): m_name(name){
    for (int i = 0; i < 4; ++i){
        m_inventory[i] = nullptr;
    }
}

Character::Character(const Character& other){
    *this = other;
}

Character& Character::operator=(const Character& other){
    if (this != &other){
        delete this;
        this = new Character(name)
    }
}
