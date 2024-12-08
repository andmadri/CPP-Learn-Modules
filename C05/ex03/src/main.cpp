#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

#include <iostream>

int main(){
	try {
		Bureaucrat Joe_Biden("Joe Biden", 1);
		Bureaucrat Kelly_Biden("Kelly Biden", 1);

		ShrubberyCreationForm Home("Home");
		RobotomyRequestForm Roboto("Roboto");
		PresidentialPardonForm Hunter_Biden("Hunter Biden");

		Joe_Biden.signForm(Home);
		Kelly_Biden.signForm(Roboto);
		Kelly_Biden.executeForm(Roboto);
	}
	catch(const AForm::GradeTooHighException& e) {
		std::cerr << "Error Form: " << e.what() << std::endl;
	} catch(const AForm::GradeTooLowException& e) {
		std::cerr << "Error Form: " << e.what() << std::endl;
	} catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Error Bureaucrat: " << e.what() << std::endl;
	} catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Error Bureaucrat: " << e.what() << std::endl;
	}
}