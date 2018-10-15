#include "../include/Point.h"

Point::Point():_x(0), _y(0), _z(0)
{

}

Point::Point(double x, double y, double z): Point()
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Point::~Point()
{

}

Point Point::operator=(const Point& p)
{
    this->_x=p.get_x();
    this->_y=p.get_y();
    this->_z=p.get_z();

    return *this;
}

double Point::get_x() const
{
	return this->_x;
}

double Point::get_y() const
{
	return this->_y;
}

double Point::get_z() const
{
	return this->_z;
}

void Point::set_x(double x)
{
	this->_x = x;
}

void Point::set_y(double y)
{
	this->_y = y;
}

void Point::set_z(double z)
{
	this->_z = z;
}
