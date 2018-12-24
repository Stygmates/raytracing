#include "Sphere.h"
#include <math.h>
using namespace std;
Sphere::Sphere(): _center(Point()), _radius(0.f)
{
}

Sphere::Sphere(Point center, float radius): _center(center), _radius(radius)
{
    if(this->_radius < 0)
    {
        cerr << "Negative radius, setting radius to 0" << endl;
        this->_radius = 0;
    }
}

Point Sphere::get_min_bounding_box()
{
    float min_x = this->_center.get_x() - this->_radius;
    float min_y = this->_center.get_y() - this->_radius;
    float min_z = this->_center.get_z() - this->_radius;
    return Point(min_x, min_y, min_z);
}

Point Sphere::get_max_bounding_box()
{
    float max_x = this->_center.get_x() + this->_radius;
    float max_y = this->_center.get_y() + this->_radius;
    float max_z = this->_center.get_z() + this->_radius;
    return Point(max_x, max_y, max_z);
}


optional<HitRecord> Sphere::ray_intersect(Ray r)
{
    float epsilon = 0.01f;
    Vector oc(this->_center, r.get_source());
    float a = r.get_direction()*r.get_direction();
    float b = 2.0*oc*r.get_direction();
    float c = oc*oc - this->_radius*this->_radius;
    float discriminant = b*b - 4*a*c;
    if(discriminant > 0)
    {
        float solution = (-b - sqrt(discriminant))/2*a;
        if(solution > epsilon)
        {
            Point intersection = r.get_point_at_parameter(solution);
            Vector normal(this->_center, intersection);
            normal.set_x(normal.get_x()/this->_radius);
            normal.set_y(normal.get_y()/this->_radius);
            normal.set_z(normal.get_z()/this->_radius);
            return HitRecord(intersection, normal);
        }
        solution = (-b + sqrt(discriminant))/2*a;
        if(solution > epsilon)
        {
            Point intersection = r.get_point_at_parameter(solution);
            Vector normal(this->_center, intersection);
            normal.set_x(normal.get_x()/this->_radius);
            normal.set_y(normal.get_y()/this->_radius);
            normal.set_z(normal.get_z()/this->_radius);
            return HitRecord(intersection, normal);
        }

    }
    return {};
}
