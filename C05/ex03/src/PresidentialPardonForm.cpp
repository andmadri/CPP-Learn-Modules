#include "../incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), m_target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), m_target(other.m_target){
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		this->m_target = other.m_target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
		if (!this->getSigned()) {
		throw AForm::FormNotSigned();
	} else if (executor.getGrade() > this->getGradeToExec()) {
			throw AForm::GradeTooLowException();
	}
	std::cout << this->m_target + "has been pardoned by Zaphold Beeblebrox" << std::endl;
}