#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../incl/AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm{
public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  ~PresidentialPardonForm() = default;

  void execute(const Bureaucrat& executor) const override;

private:
	std::string m_target;

};

#endif
