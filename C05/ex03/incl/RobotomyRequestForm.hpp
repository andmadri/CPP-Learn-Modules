#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../incl/AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm: public AForm{
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm() = default;

	void execute(const Bureaucrat& executor) const override;

private:
	std::string m_target;

};

#endif