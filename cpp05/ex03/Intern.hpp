#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const std::string &name, const int grade);
        Intern(const Intern &obj);
        ~Intern();
        Intern &operator=(const Intern &obj);
        AForm *makeForm(const std::string &nameForm, const std::string &target);
    private:
        AForm *makeRobotomyRequestForm(const std::string &target);
        AForm *makePresidentialPardonForm(const std::string &target);
        AForm *makeShrubberyCreationForm(const std::string &target);
};