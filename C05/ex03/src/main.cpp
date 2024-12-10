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
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->execute(Martin);
	delete rrf; //what will happen if I catch
	}
	catch (const Form::FormDoesntExist& e){
		std::cout << e.what() << std::endl;
		delete rrf;
	}
}