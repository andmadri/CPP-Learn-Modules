#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "../incl/AForm.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm{
public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm() = default;

  void execute(const Bureaucrat& executor) const override;

private:
	std::string m_target;

};

#endif
