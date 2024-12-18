#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

#include <iostream>

int main(){
	try {
		Bureaucrat Joe_Biden("Joe Biden", 1);
		Bureaucrat Kelly_Biden("Kelly Biden", 1999);

		ShrubberyCreationForm Home("Home");
		RobotomyRequestForm Roboto("Roboto");
		PresidentialPardonForm Hunter_Biden("Hunter Biden");

		Joe_Biden.signForm(Home);
		Kelly_Biden.signForm(Roboto);
		Kelly_Biden.executeForm(Roboto);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}