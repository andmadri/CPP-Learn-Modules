#include "../incl/Intern.hpp"

Form* Intern::makeForm(const std::string form_name, const std::string form_target) {
    form_type_t form_array[] = {
        {"shrubbery creation", [](const std::string target) { return new ShrubberyCreationForm(target) ;}},
        {"robotomy request", [](const std::string target) { return new RobotomyRequestForm(target) ;}},
        {"presidential pardon", [](const std::string target) { return new PresidentialPardonForm(target) ;}}
    };
    for (form_type_t const& formtype: form_array) {
        if (formtype.form_name_s == form_name) {
            return formtype.createForm(form_target);
            break ;
        }
    }
    throw Form::FormDoesntExist();
    return nullptr;
}
