#include "../incl/RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), m_target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), m_target(other.m_target){
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		this->m_target = other.m_target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
		if (!this->getSigned()) {
		throw AForm::FormNotSigned();
	} else if (executor.getGrade() > this->getGradeToExec()) {
			throw AForm::GradeTooLowException();
	}
	std::cout << "[drilling noises!!]" << std::endl;
	std::srand(std::time(0));
	if (rand() % 2) {
		std::cout << this->m_target + " has been robotomized" << std::endl;
	} else {
		std::cout << this->m_target + " robotomy has failed" << std::endl;
	}
}
