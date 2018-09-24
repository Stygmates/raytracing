#include "../include/Vector.h"

Vector::Vector()
{

}

Vector::Vector(Point p1, Point p2): _p1(p1), _p2(p2)
{

}

Vector::~Vector()
{

}

Point Vector::get_p1(Point p1)
{
	return this->_p1;
}

Point Vector::get_p2(Point p2)
{
	return this->_p2;
}

void Vector::set_p1(Point p1)
{
	this->_p1 = p1;
}

void Vector::set_p2(Point p2)
{
	this->_p2 = p2;
}
