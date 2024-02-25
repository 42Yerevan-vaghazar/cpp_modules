#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 145, 137) {
    m_target = target;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {
    m_target = obj.m_target;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        m_target = obj.m_target;
    }
    return (*this);
};

void PresidentialPardonForm::action() const {
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};