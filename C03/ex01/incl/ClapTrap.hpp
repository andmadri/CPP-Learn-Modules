#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{

public:

    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string& getName();
    int getHitPoints();
    int getEnergyPoints();
    int getAttackDamage();

private:

    std::string m_name;
    int m_hit_points;
    int m_energy_points;
    int m_attack_damage;

};

#endif