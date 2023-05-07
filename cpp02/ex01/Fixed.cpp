#include "Fixed.hpp"
#include <iostream>
#include <math.h>

const int Fixed::m_nFractBits = 8;

Fixed::Fixed() : m_raw(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num) {
	std::cout << "parametr int constructor called" << std::endl;
	m_raw = num * pow(2, m_nFractBits);
};

Fixed::Fixed(const float num) {
	std::cout << "parametr float constructor called" << std::endl;
	m_raw = roundf(num * pow(2, m_nFractBits));
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

float Fixed::toFloat(void) const {
	return (static_cast <float> (this->getRawBits()) / pow(2, m_nFractBits));
};

int Fixed::toInt(void) const {
	return (this->getRawBits() / pow(2, m_nFractBits));
};

int Fixed::getRawBits(void) const {
	return (m_raw);
};

void Fixed::setRawBits(int const raw) {
	m_raw = raw;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	std::cout << obj.toFloat();
	return (out);
};
