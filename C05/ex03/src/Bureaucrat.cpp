#include "../incl/Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat){
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(): m_name("Unamed"), m_grade(150){
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: m_name(name){
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): m_name(other.m_name), m_grade(other.m_grade){
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other){
		this->m_grade = other.m_grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->m_name;
}

int Bureaucrat::getGrade() const{
	return this->m_grade;
}

void Bureaucrat::increment(int num){
	if (this->getGrade() - num <= 0) {
		throw GradeTooHighException();
	}
	if (this->getGrade() - num > 150) {
		throw GradeTooLowException();
	}
	this->m_grade -= num;
}

void Bureaucrat::decrement(int num){
	if (this->getGrade() + num <= 0) {
		throw GradeTooHighException();
	}
	if(this->getGrade() + num > 150) {
		throw GradeTooLowException();
	}
	m_grade += num;
}

void Bureaucrat::signForm(Form& Form){
	try {
		Form.beSigned(*this);
		std::cout << this->getName() << " signed Form " << Form.getName() << " of grade " << Form.getGradeToSign() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->getName() << " couldn't sign Form " << Form.getName() << " because grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& form){
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed Form " << form.getName() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
		std::cout << this->getName() << " couldn't execute Form " << form.getName() << " because the grade is too low" << std::endl;
	} catch (const Form::FormNotSigned& e) {
		std::cout << e.what() << std::endl;
		std::cout << this->getName() << " couldn't execute Form " << form.getName() << " because the form is not signed" << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Grade is too low";
}
