#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../incl/Form.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form{
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
