#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "../incl/MyException.hpp"

class Bureaucrat{

private:
	const std::string m_name;
	int m_grade; //from 1 to 150

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat() = default;

	std::string getName() const;
	int getGrade() const;

	void increment(int num); //incrementing a grade 3 = 2
	void decrement(int num); //decrementing a grade 3 = 4;

	class GradeTooHighException: public exception{
		const char* what() const override noexcept;
	};
	class GradeTooLowException: public exception{
		const char* what() const override noexcept;
	};

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat);

#endif
