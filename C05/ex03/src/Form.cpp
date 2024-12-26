#include "../incl/Form.hpp"

std::ostream& operator<<(std::ostream& out, const Form& Form){
    out << "Form: " << Form.getName() << std::endl;
    out << "Signed: " << Form.getSigned() << std::endl;
    out << "Grade to Sign: " << Form.getGradeToSign() << std::endl;
    out << "Grade to Execute: " << Form.getGradeToExec() << std::endl;
    return out;
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
    if (Bureaucrat.getGrade() <= this->getGradeToSign()) {
        m_signed = true;
    } else {
        throw GradeTooLowException();
    }
}
    
const char* Form::GradeTooLowException::what() const noexcept{
    return "Grade is too low, it should be between 1 to 150";
}

const char* Form::GradeTooHighException::what() const noexcept{
    return "Grade is too high, it should be between 1 to 150";
}

const char* Form::FormNotSigned::what() const noexcept{
    return "Form is not yet signed";
}

const char* Form::FormDoesntExist::what() const noexcept{
    return "Form type does not exist";
}
