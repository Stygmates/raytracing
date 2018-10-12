#include "../include/Vector.h"

Vector::Vector()
{

}

Vector::Vector(Point p1, Point p2)
{
	this->_x = p2.get_x() - p1.get_x();
	this->_y = p2.get_y() - p1.get_y();
	this->_z = p2.get_z() - p1.get_z();
}

Vector::Vector(int x, int y, int z): _x(x), _y(y), _z(z)
{
}

Vector::~Vector()
{

}

void Vector::set_x(int x)
{
	this->_x = x;
}

void Vector::set_y(int y)
{
	this->_y = y;
}

void Vector::set_z(int z)
{
	this->_z = z;
}

int Vector::get_x() const
{
	return this->_x;
}

int Vector::get_y() const 
{
	return this->_y;
}

int Vector::get_z() const 
{
	return this->_z;
}
void Vector::set_v(int x, int y,int z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Vector Vector::operator=(const Vector& v)
{
	this->_x=v.get_x();
	this->_y=v.get_y();
	this->_z=v.get_z();

	return *this;
}
Vector Vector::operator^(const Vector& v)
{
	Vector vec;
	vec.set_x ( this->_y * v.get_z() - v.get_y() * this->_z);
	vec.set_y ( this->_z * v.get_x() - v.get_z() * this->_x);
	vec.set_z ( this->_x * v.get_y() - v.get_x() * this->_y);
	
	return vec;
}

double Vector::operator*(const Vector& v)
{
	return this->_x * v.get_x() + this->_y * v.get_y() + this->_z * v.get_z();
}


Vector Vector::operator+(const Vector& v)
{
	Vector sum;
	sum.set_x(this->_x + v.get_x());
	sum.set_y(this->_y + v.get_y());
	sum.set_z(this->_z + v.get_z());

	return sum;
}

