#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"

int main(){
	Intern someRandomIntern;
	Form* rrf = NULL;
	try{

	Bureaucrat Martin("Martin", 1);
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");

	Martin.signForm(*rrf);
	Martin.executeForm(*rrf);

	std::cout << Martin << std::endl;
	std::cout << *rrf << std::endl;
	delete rrf;
	} catch (const std::exception& e) {
		if (rrf)
			delete rrf;
		std::cerr << e.what() << std::endl;
	}
}