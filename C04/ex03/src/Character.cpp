#include "../incl/Character.hpp"

Character::Character(): m_name(""){
    for (int i = 0; i < 4; ++i){
        m_inventory[i] = nullptr;
        m_dscrd_inventory[i] = nullptr;
    }
}

Character::Character(const std::string& name): m_name(name){
    for (int i = 0; i < 4; ++i){
        m_inventory[i] = nullptr;
        m_dscrd_inventory[i] = nullptr;
    }
}

Character::Character(const Character& other){
    *this = other;
}

Character& Character::operator=(const Character& other){
    if (this != &other){
        for(int i = 0; i < 4; ++i){
            delete this->m_inventory[i];
            delete this->m_dscrd_inventory[i];
            this->m_inventory[i] = nullptr;
            this->m_dscrd_inventory[i] = nullptr;
        }
        this->m_name = other.m_name;
        for (int i = 0; i < 4; ++i){
            if (other.m_inventory[i]){
                this->m_inventory[i] = other.m_inventory[i]->clone();
            }
            if (other.m_dscrd_inventory[i]){
                this->m_dscrd_inventory[i] = other.m_dscrd_inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; ++i){
        if (m_dscrd_inventory[i])
            delete m_dscrd_inventory[i];
    }
}

std::string const& Character::getName() const{
    return m_name;
}

void Character::equip(AMateria *m){
    for (int i = 0; i < 4; ++i){
        if (!m_inventory[i]){
            m_inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx){
    if (idx >= 0 && idx < 4){
        if (m_inventory[idx]){
            for (int i = 0; i < 4; ++i){
                if (!m_dscrd_inventory[i]){
                      m_dscrd_inventory[i ]= m_inventory[idx];
                }
            }
            m_inventory[idx] = nullptr;
        }
    }
}

void Character::use(int idx, ICharacter &target){
    if (idx >= 0 && idx < 4){
        if (m_inventory[idx]){
            m_inventory[idx]->use(target);
        }
    }
}
