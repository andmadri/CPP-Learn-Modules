#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"

int main(){
	Intern someRandomIntern;
	Form* rrf;
	try{

	Bureaucrat Martin("Martin", 1);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	Martin.signForm(*rrf);
	Martin.executeForm(*rrf);

	std::cout << Martin << std::endl;
	std::cout << *rrf << std::endl;
	delete rrf;
	}
	catch (const Form::FormDoesntExist& e){
		std::cout << e.what() << std::endl;
	}
	catch (const Form::FormNotSigned& e){
		std::cout << e.what() << std::endl;
		delete rrf;
	}
}