#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    m_type = "Cat";
    m_brain = new Brain();
};

Cat::Cat(const std::string &name) {
    m_type = name;
    m_brain = new Brain();
    std::cout << "Cat parametr constructor called" << std::endl;
};

Cat::Cat(const Cat &obj) {
    std::cout << "Cat copy constructor called" << std::endl;
    m_type = obj.m_type;
    m_brain = new Brain(*obj.m_brain);
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete m_brain;
};

Cat &Cat::operator=(const Cat &obj) {
    std::cout << "Cat assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
        *m_brain = *obj.m_brain;
    }
    return (*this);
};

void Cat::makeSound() const {
    std::cout << "Cat is barking" << std::endl;
};