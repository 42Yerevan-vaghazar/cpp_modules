#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure default constructor called" << std::endl;
};

Cure::Cure(const Cure &obj) : AMateria(obj.m_type) {};

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
};

Cure &Cure::operator=(const Cure &obj) {
    AMateria::operator=(obj); // TODO is this true
    // m_type = obj.m_type;
    return (*this);
};

AMateria* Cure::clone() const {
    return (new Cure(*this));
};