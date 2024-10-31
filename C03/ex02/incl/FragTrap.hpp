#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "../incl/ClapTrap.hpp";

class FragTrap: public ClapTrap{

public:

  FragTrap(std::string& name);
  FragTrap(FragTrap& other);
  FragTrap& operator=(FragTrap& other);
  ~FragTrap();
  void highFivesGuys(void);
};

#endif