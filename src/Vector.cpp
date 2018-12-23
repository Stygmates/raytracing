#include <math.h>
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

Vector::Vector(float x, float y, float z): _x(x), _y(y), _z(z)
{
}

Vector::~Vector()
{

}

void Vector::set_x(float x)
{
	this->_x = x;
}

void Vector::set_y(float y)
{
	this->_y = y;
}

void Vector::set_z(float z)
{
	this->_z = z;
}


Point Vector::get_translation(Point p)
{
    float x = p.get_x() + this->get_x();
    float y = p.get_y() + this->get_y();
    float z = p.get_z() + this->get_z();
    return Point(x, y, z);
}

float Vector::get_x() const
{
	return this->_x;
}

float Vector::get_y() const
{
	return this->_y;
}

float Vector::get_z() const
{
	return this->_z;
}
void Vector::set_v(float x, float y, float z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

float Vector::norm()
{
    float square = this->get_x() * this->get_x() + this->get_y() * this->get_y() + this->get_z() * this->get_z();
    return sqrt(square);
}

Vector Vector::unit()
{
    float norm = this->norm();
    Vector result(this->get_x()/norm,this->get_y()/norm, this->get_z()/norm);
    return result;
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

float Vector::operator*(const Vector& v)
{
    return this->_x * v.get_x() + this->_y * v.get_y() + this->_z * v.get_z();
}

Vector Vector::operator*(const float &t)
{
    return Vector(this->_x * t, this->_y * t, this->_z * t);
}


Vector Vector::operator+(const Vector& v)
{
	Vector sum;
	sum.set_x(this->_x + v.get_x());
	sum.set_y(this->_y + v.get_y());
	sum.set_z(this->_z + v.get_z());

    return sum;
}

Vector Vector::operator-(const Vector &v)
{
    Vector sub;
    sub.set_x(this->_x - v.get_x());
    sub.set_y(this->_y - v.get_y());
    sub.set_z(this->_z - v.get_z());

    return sub;
}

