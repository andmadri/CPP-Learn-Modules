#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include <exception>

class AForm;

class Intern {
private:

public:
  Intern() = default;
  Intern(const Intern& other) = default;
  Intern& operator=(const Intern& other) = default;
  ~Intern() = default;

  AForm* makeForm(const std::string form_name, const std::string form_target);

  class FormDoesntExist: public std::exception {
  public:
    const char* what() const noexcept override;
  };

  typedef struct form_type_s {
    const std::string form_name_s;
    AForm* (*create)(const std::string form_target_s);
  } form_type_t;
};

#endif