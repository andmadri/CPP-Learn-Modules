#include "../incl/Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat){
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return out;
}

//can two Bureaucrats have the same grade

Bureaucrat::Bureaucrat(): m_name("Unamed"), m_grade("150"){
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

//Bureaucrat copy constructor
//Bureaucrat copy assignment operator

std::string Bureaucrat::getName() const{
	return this->m_name;
}

int Bureaucrat::getGrade() const{
	return this->m_grade;
}

void Bureaucrat::increment(int num){
	if (this->getGrade() - num <= 0) {
		throw GradeTooLowException()
	}
	if (this->getGrade() - num > 150) {
		throw GradeTooHighException()
	}
	this->getGrade() -= num;
}

void Bureaucrat::decrement(int num){
	if (this->getGrade() + num <= 0) {
		throw GradeTooLowException();
	}
	if(this->getGrade() + num > 150) {
		throw GradeTooHighException()
	}
	this->getGrade() += num;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Grade is too high, it should be between and including 1-150";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Grade is too low, it should be between and including 1-150";
}
