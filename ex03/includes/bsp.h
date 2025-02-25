#ifndef BSP_H
#define BSP_H

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

class	Fixed;
class	Point;

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif