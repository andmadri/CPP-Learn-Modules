#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include <iostream>

int main(){
	try {
		// Bureaucrat John("John", 1);
		Bureaucrat John("John", 5);
		Form Huurtoeslag("Huurtoeslag", 4, 3);
		// Form Zorgtoeslag("Zorgtoeslag", 151, -1);

		std::cout << Huurtoeslag;
		std:: cout << "\n\n";
		std::cout << John;
		John.signForm(Huurtoeslag);
		John.increment(1);
		std::cout << John;
		John.signForm(Huurtoeslag);
		John.signForm(Huurtoeslag);
		// John.decrement(1);
		// std::cout << John;
		// John.signForm(Huurtoeslag);
		// std:: cout << "\n\n";
		// std::cout << Huurtoeslag;
		// std::cout << "\n";
		// std::cout << John;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	// } catch(const Form::GradeTooLowException& e) {
	// 	std::cerr << "Error Form: " << e.what() << std::endl;
	// } catch(const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Error Bureaucrat: " << e.what() << std::endl;
	// } catch(const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Error Bureaucrat: " << e.what() << std::endl;
	// }
}