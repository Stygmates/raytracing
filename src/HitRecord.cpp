#include "HitRecord.h"

HitRecord::HitRecord(Point intersection, Vector normal, Material material, float distance): _intersection(intersection), _normal(normal), _material(material), _distance(distance)
{

}

Point HitRecord::get_intersection()
{
    return this->_intersection;
}

Vector HitRecord::get_normal()
{
    return this->_normal;
}

Material HitRecord::get_material()
{
    return this->_material;
}

float HitRecord::get_distance()
{
    return this->_distance;
}


Color HitRecord::get_color(Color lightcolor, Point lightposition, Point originCamera)
{
    return this->get_material().get_color(this->get_intersection(),this->get_normal(), lightcolor, lightposition, originCamera);
}
