#include "../incl/Intern.hpp"

AForm* Intern::makeForm(const std::string form_name, const std::string form_target) {
    form_type_t form_array[] = {
        {"shrubbery creation", [](const std::string target) { return new ShrubberyCreationForm(target) ;}},
        {"robotomy request", [](const std::string target) { return new RobotomyRequestForm(target) ;}},
        {"presidential pardon", [](const std::string target) { return new PresidentialPardonForm(target) ;}}
    };
    for (auto const& formtype: form_array) {
        if (form_array->form_name_s == form_name) {
            form_array->
        }
    }
}
