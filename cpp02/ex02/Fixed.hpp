#pragma once
#include <iostream>
#include <climits>
#include <math.h>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;
	Fixed operator+(const Fixed &fixed) ;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;
	Fixed operator++(int);
	Fixed operator++();
	Fixed operator--(int);
	Fixed operator--();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

public:
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

private:
	int m_raw;

private:
	static const int m_nFractBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);