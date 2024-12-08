#include "../incl/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), m_target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), m_target(other.m_target){
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		this->m_target = other.m_target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	if (!this->getSigned()) {
		throw AForm::FormNotSigned();
	} else if (executor.getGrade() > this->getGradeToExec()) {
			throw AForm::GradeTooLowException();
	}
	std::ofstream file(m_target + "_shrubbery");
	if (!file) {
		std::cerr << "Error while opening file: " << m_target + "_shrubbery" << std::endl;
	} else {
			file << "        *\n";
			file << "       ***\n";
			file << "      *****\n";
			file << "     *******\n";
			file << "    *********\n";
			file << "   ***********\n";
			file << "  *************\n";
			file << " ***************\n";
			file << "      |||\n";
			file << "      |||\n";
		file.close();
	}
}
