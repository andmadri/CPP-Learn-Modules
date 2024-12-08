#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "../incl/Bureaucrat.hpp"

class Bureaucrat;

class AForm{

private:
    const std::string m_name;
    bool m_signed;
    const int m_grade_to_sign;
    const int m_grade_to_exec;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    virtual ~AForm() = default;

    const std::string& getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    
    void beSigned(const Bureaucrat& Bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;
    
    class GradeTooLowException: public std::exception{
    public:
        const char* what() const noexcept override;
    };

    class GradeTooHighException: public std::exception{
    public:
        const char* what() const noexcept override;
    };

    class FormNotSigned: public std::exception{
    public:
        const char* what() const noexcept override;
    };

};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif