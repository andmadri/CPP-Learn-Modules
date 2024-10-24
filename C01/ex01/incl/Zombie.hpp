#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie{

public:

  Zombie() = default;
  Zombie(const std::string& name);
  ~Zombie();

  void           announce(void);
  static Zombie* zombieHorde(int N, std::string name);

private:

  std::string name;

};

#endif