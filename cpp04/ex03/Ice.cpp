#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
};

Ice::Ice(const Ice &obj) : AMateria(obj.m_type) {};

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
};

Ice &Ice::operator=(const Ice &obj) {
    AMateria::operator=(obj); // TODO is this true
    // m_type = obj.m_type;
    return (*this);
};

AMateria *Ice::clone() const {
    // std::cout << "*Ice::clone called" << std::endl;
    return (new Ice(*this));
}