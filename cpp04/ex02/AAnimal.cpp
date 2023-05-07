#include "AAnimal.hpp"

Animal::Animal() : m_type("animal") {
    std::cout << "Animal default constructor called" << std::endl;
   ;
};

Animal::Animal(const std::string &name) : m_type(name) {
    std::cout << "Animal parametr constructor called" << std::endl;
};

Animal::Animal(const Animal &obj) {
    std::cout << "Animal copy constructor called" << std::endl;
    m_type = obj.m_type;
};

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
};

Animal &Animal::operator=(const Animal &obj) {
    std::cout << "Animal assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
    }
    return (*this);
};

void Animal::makeSound() const {
    std::cout << "Animal makes sound" << std::endl;
};