#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
   ;
};

WrongAnimal::WrongAnimal(const std::string &name) : m_type(name) {
    std::cout << "WrongAnimal parametr constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    m_type = obj.m_type;
};

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    std::cout << "WrongAnimal assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
    }
    return (*this);
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes sound" << std::endl;
};