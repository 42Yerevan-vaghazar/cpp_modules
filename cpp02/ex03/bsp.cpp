#include "Point.hpp"

Fixed area(const Fixed x1, const Fixed y1, const Fixed x2, const Fixed y2, const Fixed x3, const Fixed y3)
{
   return abs(((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2).toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	A1 = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	A2 = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	if (A1 == 0 || A2 == 0 || A3 == 0) {
		return (false);
	}
	return (A == (A1 + A2 + A3));
};