#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    m_type = "Dog";
    m_brain = new Brain();
};

Dog::Dog(const std::string &name) {
    m_type = name;
    m_brain = new Brain();
    std::cout << "Dog parametr constructor called" << std::endl;
};

Dog::Dog(const Dog &obj) {
    std::cout << "Dog copy constructor called" << std::endl;
    m_type = obj.m_type;
    m_brain = new Brain(*obj.m_brain);
};

Dog::~Dog() {
    delete m_brain;
    std::cout << "Dog destructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
        *m_brain = *obj.m_brain;
    }
    return (*this);
};

void Dog::makeSound() const {
    std::cout << "Dog is barking" << std::endl;
};