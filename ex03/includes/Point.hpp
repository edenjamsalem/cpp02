#ifndef POINT_HPP
#define POINT_HPP

#include "bsp.h"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
		Point(float x, float y);
};

#endif
