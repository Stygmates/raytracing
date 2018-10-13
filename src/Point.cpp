#include "../include/Point.h"

Point::Point():_x(0), _y(0), _z(0)
{

}

Point::Point(float x, float y, float z): Point()
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Point::~Point()
{

}

float Point::get_x()
{
	return this->_x;
}

float Point::get_y()
{
	return this->_y;
}

float Point::get_z()
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
