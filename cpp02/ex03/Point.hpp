#pragma once
#include <iostream>
#include "Fixed.hpp"
#include <math.h>

class Point
{
    public:
    	Point();
    	Point(const float x, const float y);
        Point(const Point &obj);
        ~Point();
        Point &operator=(const Point &obj);
        const Fixed &getX() const;
        const Fixed &getY() const;
    private:
        const Fixed m_x;
        const Fixed m_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);