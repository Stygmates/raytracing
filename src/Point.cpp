#include "../include/Point.h"

Point::Point():_x(0), _y(0), _z(0)
{

}

Point::Point(float x, float y, float z): _x(x), _y(y), _z(z)
{

}

Point::~Point()
{

}

float Point::get_x() const
{
	return this->_x;
}

float Point::get_y() const
{
	return this->_y;
}

float Point::get_z() const
{
	return this->_z;
}

void Point::set_x(float x)
{
	this->_x = x;
}

void Point::set_y(float y)
{
	this->_y = y;
}

void Point::set_z(float z)
{
	this->_z = z;
}

Point Point::operator+(Point& v)
{
    Point sum;
    sum.set_x(this->_x + v.get_x());
    sum.set_y(this->_y + v.get_y());
    sum.set_z(this->_z + v.get_z());

    return sum;
}

bool Point::operator!=(Point& v)
{
    return ((this->get_x() != v.get_x()) || (this->get_y() != v.get_y()) || (this->get_z() != v.get_z()));
}
