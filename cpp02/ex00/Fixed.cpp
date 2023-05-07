#include "Fixed.hpp"
#include <iostream>

const int Fixed::m_nFractBits = 8;

Fixed::Fixed() : m_raw(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed) {
    m_raw = fixed.m_raw;
    std::cout << "Copy constructor called" << std::endl;
};

Fixed::~Fixed() {
    std::cout << "Default Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &fixed) {
    m_raw = fixed.m_raw;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
};

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (m_raw);
};

void Fixed::setRawBits(int const raw) {
    m_raw = raw;
    std::cout << "setRawBits member function called" << std::endl;
};