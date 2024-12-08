#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "../incl/Form.hpp"

class Form;

class Bureaucrat{

private:
	const std::string m_name;
	int m_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat() = default;

	std::string getName() const;
	int getGrade() const;

	void increment(int num);
	void decrement(int num);
	void signForm(Form& Form);

	class GradeTooHighException: public std::exception{
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException: public std::exception{
	public:
		const char* what() const noexcept override;
	};

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat);

#endif
