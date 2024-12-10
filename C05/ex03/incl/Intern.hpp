#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "../incl/Form.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include <exception>
#include <functional>

class Form;

class Intern {
private:

public:
  Intern() = default;
  Intern(const Intern& other) = default;
  Intern& operator=(const Intern& other) = default;
  ~Intern() = default;

  Form* makeForm(const std::string form_name, const std::string form_target);

  typedef struct form_type_s {
    const std::string form_name_s;
    std::function<Form* (const std::string&)> createForm;
  } form_type_t;
};

#endif