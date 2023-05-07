#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Cat default constructor called" << std::endl;
    m_type = "Cat";
};

WrongCat::WrongCat(const std::string &name) {
    m_type = name;
    std::cout << "WrongCat parametr constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &obj) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    m_type = obj.m_type;
};

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    std::cout << "WrongCat assignment aoperator called" << std::endl;
    if (this != &obj) {
        m_type = obj.m_type;
    }
    return (*this);
};

void WrongCat::makeSound() const {
    std::cout << "WrongCat is barking" << std::endl;
};