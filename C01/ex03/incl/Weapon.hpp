#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{

public:

    Weapon() = default;
    Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(const std::string& new_type);

private:

    std::string type;


};

#endif