#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "../incl/Bureaucrat.hpp"

class Bureaucrat;

class Form{

private:
    const std::string m_name;
    bool m_signed;
    const int m_grade_to_sign;
    const int m_grade_to_exec;

public:
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form() = default;

    const std::string& getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    
    void beSigned(const Bureaucrat& Bureaucrat);
    
    class GradeTooLowException: public std::exception{
    public:
        const char* what() const noexcept override;
    };

    class GradeTooHighException: public std::exception{
    public:
        const char* what() const noexcept override;
    };

};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif