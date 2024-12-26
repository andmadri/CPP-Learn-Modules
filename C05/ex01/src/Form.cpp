#include "../incl/Form.hpp"

std::ostream& operator<<(std::ostream& out, const Form& Form){
    out << "Form: " << Form.getName() << std::endl;
    out << "Signed: " << Form.getSigned() << std::endl;
    out << "Grade to Sign: " << Form.getGradeToSign() << std::endl;
    out << "Grade to Execute: " << Form.getGradeToExec() << std::endl;
    return out;
}

Form::Form(): m_name(""), m_signed(false), 
m_grade_to_sign(1), m_grade_to_exec(1){
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
: m_name(name), m_signed(false), 
m_grade_to_sign(gradeToSign), m_grade_to_exec(gradeToExec){
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
}
    
Form::Form(const Form& other): m_name(other.m_name), m_signed(other.m_signed),
m_grade_to_sign(other.m_grade_to_sign), m_grade_to_exec(other.m_grade_to_exec){
    *this = other;
}

Form& Form::operator=(const Form& other){
    if (this != &other){
        this->m_signed = other.m_signed;
    }
    return *this;
}

const std::string& Form::getName() const{
    return m_name;
}

bool Form::getSigned() const{
    return m_signed;
}

int Form::getGradeToSign() const{
    return m_grade_to_sign;
}

int Form::getGradeToExec() const{
    return m_grade_to_exec;
}

void Form::beSigned(const Bureaucrat& Bureaucrat){
    if (Bureaucrat.getGrade() <= this->getGradeToSign() && !m_signed) {
        m_signed = true;
    } else if (Bureaucrat.getGrade() > this->getGradeToSign() && !m_signed){
        throw GradeTooLowException();
    } else {
        throw FormPreviouslySigned();
    }
}
    
const char* Form::GradeTooLowException::what() const noexcept{
    return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const noexcept{
    return "Grade is too high";
}

const char* Form::FormPreviouslySigned::what() const noexcept{
    return "Form is already signed";
}
