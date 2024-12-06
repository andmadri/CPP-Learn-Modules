#include "../incl/Bureaucrat.hpp"
#include <iostream>

int main(){
	try {
		Bureaucrat John("John", 14);
		Bureaucrat Melody("Melody", 1);
		Bureaucrat Sara("Sara", 150);
		Bureaucrat Pascal("Pascal", -14);
		Bureaucrat Alex("Alex", 151);

		std::cout << John;
		std::cout << Melody;
		std::cout << Sara;
		std::cout << Pascal;
		std::cout << Alex;
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}