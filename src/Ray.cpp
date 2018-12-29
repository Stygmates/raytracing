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

vector<Point> Ray::stochastic_sampling(int n)
{
    vector<Point> matrix_sampling;
    Point random_point(0,0,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            float x = ( i + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)) ) / n;
            float y = ( j + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)) ) / n;

            random_point.set_x(x/(float)pixel_per_unit );
            random_point.set_y(y/(float)pixel_per_unit );
            random_point.set_z(0.f );

            matrix_sampling.push_back(random_point);

        }
    }
return matrix_sampling;
}

void Ray::translate_ray_to_screen()
{
    Vector translate(this->_direction.get_x()-this->_source.get_x(),
                    this->_direction.get_y()-this->_source.get_y(),
                    this->_direction.get_z()-this->_source.get_z());

    this->set_source(Point(this->_direction.get_x(), this->_direction.get_y(), this->_direction.get_z()) );
    this->set_direction(this->get_direction() + translate);
}

void Ray::ray_unit()
{
    Vector direction_unit = this->_direction.unit();
    this->set_direction(Vector( this->_source.get_x() + direction_unit.get_x(),
                                this->_source.get_y() + direction_unit.get_y(),
                                this->_source.get_z() + direction_unit.get_z()) );
}
