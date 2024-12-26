#include "../incl/AForm.hpp"

std::ostream& operator<<(std::ostream& out, const AForm& AForm){
    out << "Form: " << AForm.getName() << std::endl;
    out << "Signed: " << AForm.getSigned() << std::endl;
    out << "Grade to Sign: " << AForm.getGradeToSign() << std::endl;
    out << "Grade to Execute: " << AForm.getGradeToExec() << std::endl;
    return out;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
: m_name(name), m_signed(false), 
m_grade_to_sign(gradeToSign), m_grade_to_exec(gradeToExec){
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
}

const std::string& AForm::getName() const{
    return m_name;
}

bool AForm::getSigned() const{
    return m_signed;
}

int AForm::getGradeToSign() const{
    return m_grade_to_sign;
}

int AForm::getGradeToExec() const{
    return m_grade_to_exec;
}

void AForm::beSigned(const Bureaucrat& Bureaucrat){
    if (Bureaucrat.getGrade() <= this->getGradeToSign()) {
        m_signed = true;
    } else {
        throw GradeTooLowException();
    }
}
    
const char* AForm::GradeTooLowException::what() const noexcept{
    return "Grade is too low, it should be between 1 to 150";
}

const char* AForm::GradeTooHighException::what() const noexcept{
    return "Grade is too high, it should be between 1 to 150";
}

const char* AForm::FormNotSigned::what() const noexcept{
    return "Form is not yet signed";
}
