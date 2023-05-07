#include "Fixed.hpp"

const int Fixed::m_nFractBits = 8;

Fixed::Fixed() : m_raw(0) {
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num) {
	// std::cout << "parametr int constructor called" << std::endl;
	m_raw = num * (1 << m_nFractBits);
};

Fixed::Fixed(const float num) {
	// std::cout << "parametr float constructor called" << std::endl;
	m_raw = roundf((num) * (1 << m_nFractBits));
};

Fixed::Fixed(const Fixed &fixed) {
	m_raw = fixed.m_raw;
	// std::cout << "Copy constructor called" << std::endl;
};

Fixed::~Fixed() {
	// std::cout << "Default Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &fixed) {
	m_raw = fixed.m_raw;
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
};

bool Fixed::operator>(const Fixed &fixed) const {
	return (this->getRawBits() > fixed.getRawBits());
};

bool Fixed::operator<(const Fixed &fixed) const {
	return (this->getRawBits() < fixed.getRawBits());
};

bool Fixed::operator>=(const Fixed &fixed) const {
	return (this->getRawBits() >= fixed.getRawBits());
};

bool Fixed::operator<=(const Fixed &fixed) const {
	return (this->getRawBits() <= fixed.getRawBits());
};

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->getRawBits() == fixed.getRawBits());
};

bool Fixed::operator!=(const Fixed &fixed) const {
	return (this->getRawBits() != fixed.getRawBits());
};

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (tmp);
};

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (tmp);
};

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed tmp;

	tmp.setRawBits(roundf(this->toFloat() * fixed.toFloat() * (1 << m_nFractBits)));  // TODO
	return (tmp);
};

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed tmp;

	if (fixed == 0)
		throw std::logic_error("Division by zero");
	tmp.setRawBits(roundf((this->toFloat() / fixed.toFloat()) * (1 << m_nFractBits)));
	return (tmp);
};

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
};

Fixed Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
};

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
};

Fixed Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
};

float Fixed::toFloat(void) const {
	return (static_cast <float> (this->getRawBits()) / (1 << m_nFractBits));
};

int Fixed::toInt(void) const {
	return (this->getRawBits() / (1 << m_nFractBits));
};

int Fixed::getRawBits(void) const {
	return (m_raw);
};

void Fixed::setRawBits(int const raw) {
	m_raw = raw;
};

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed1 : fixed2);
};

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed1 : fixed2);
};

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed1 : fixed2);
};

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed1 : fixed2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	std::cout << obj.toFloat();
	return (out);
};
