#include "../incl/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& other){
    *this = other;
}

Brain& Brain::operator=(const Brain& other){
    if (this != &other){
        for (int i = 0; i < 100; ++i){
            this->m_ideas[i] = other.m_ideas[i];
        }
        std::cout << "Deep Copy created" << std::endl;
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destroyed" << std::endl;
}