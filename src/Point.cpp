#include "../include/Point.h"

Point::Point():x(0), y(0), z(0)
{

}

Point::Point(int x, int y, int z): _x(x), _y(y), _z(z)
{

}

Point::~Point()
{

}

int Point::get_x()
{
	return this->_x;
}

int Point::get_y()
{
	return this->_y;
}

int Point::get_z()
{
	return this->_z;
}

void Point::set_x(int x)
{
	this->_x = x;
}

void Point::set_y(int y)
{
	this->_y = y;
}

void Point::set_z(int z)
{
	this->_z = z;
}
