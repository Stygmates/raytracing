#include "../include/Ray.h"

Ray::Ray()
{

}

Ray::Ray(Point source, Vector direction)
{
	this->_source = source;
	this->_direction = direction;	
}

Ray::~Ray()
{

}

Point Ray::get_source()
{
	return this->_source;
}

Vector Ray::get_direction()
{
	return this->_direction;
}

void Ray::set_source(Point source)
{
	this->_source = source;
}

void Ray::set_direction(Vector direction)
{
	this->_direction = direction;
}

Point Ray::get_point_at_parameter(double t)
{
    Vector translation = t * this->get_direction();
    return translation.get_translation(this->get_source());
}
