#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("presidential pardon", 145, 137) {
    std::cout << __func__ << " called" << std::endl;
    m_target = target;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    m_target = obj.m_target;
};

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << __func__ << " called" << std::endl;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        m_target = obj.m_target;
    }
    return (*this);
};

void PresidentialPardonForm::action() const {
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};