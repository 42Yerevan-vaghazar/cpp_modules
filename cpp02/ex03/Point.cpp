#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) {};

Point::Point(const float x, const float y) : m_x(x), m_y(y) {};

Point::Point(const Point &obj) :  m_x(obj.m_x), m_y(obj.m_y) {};

Point &Point::operator=(const Point &obj) {(void)obj; return (*this);};

Point::~Point() {};

const Fixed &Point::getX() const {
	return (m_x);
};

const Fixed &Point::getY() const {
	return (m_y);
};

