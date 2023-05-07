#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    m_type = "Dog";
};

Dog::Dog(const std::string &name) {
    m_type = name;
    std::cout << "Dog parametr constructor called" << std::endl;
};

Dog::Dog(const Dog &obj) {
    std::cout << "Dog copy constructor called" << std::endl;
    m_type = obj.m_type;
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
    }
    return (*this);
};

void Dog::makeSound() const {
    std::cout << "Dog is barking" << std::endl;
};