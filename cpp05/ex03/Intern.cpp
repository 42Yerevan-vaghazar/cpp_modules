#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

  
Intern::Intern() {
    std::cout << __func__ << " called" << std::endl;
};
Intern::Intern(const Intern &obj) {
    (void)obj;
};

Intern::~Intern() {
    std::cout << __func__ << " called" << std::endl;
};

Intern &Intern::operator=(const Intern &obj) {
     (void)obj;
    return (*this);
};

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
    return (new RobotomyRequestForm(target));
};

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
    return (new PresidentialPardonForm(target));
};

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
    return (new ShrubberyCreationForm(target));
};


AForm *Intern::makeForm(const std::string &nameForm, const std::string &target) {

    const int formCount = 3;
    std::string formNames[formCount] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    std::cout << "Intern creates " << nameForm << std::endl;
    AForm *(Intern::*forms[formCount])(const std::string &target);

    forms[0] = &Intern::makeShrubberyCreationForm;
    forms[1] = &Intern::makePresidentialPardonForm;
    forms[2] = &Intern::makeRobotomyRequestForm;

    for (int i = 0; i < formCount; i++) {
        if (nameForm == formNames[i]) {
            return (((this->*forms[i]))(target));
        }
    }
    std::cout << "nameForm does not match any form" << std::endl;
    return (NULL);
}; 