#include "../includes/bsp.h"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
	}
	return *this;
}

Point::~Point() {}

Point::Point(float x, float y): _x(x), _y(y) {}
