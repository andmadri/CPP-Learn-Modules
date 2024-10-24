#include "../incl/Harl.hpp"

typedef void (Harl::*Harlfunctions) ();

void Harl::debug(void){
  std::cout << "I love having bacon for my triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void){
  std::cout << "I cannot believe adding extra bacon costs more money!\n";
  std::cout << "You did not put enough bacon in my burger!\n";
  std::cout << "If you did, I would not be asking for more!\n";
}

void Harl::warning(void){
  std::cout << "I think I deserve to have some extra bacon for free.\n";
  std::cout << "I have been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void){
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
  Harlfunctions functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; ++i){
    if (levels[i] == level){
      (this->*functions[i])();
    }
  }
}
