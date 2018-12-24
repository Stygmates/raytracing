#include "HitRecord.h"

HitRecord::HitRecord(Point intersection, Vector normal): _intersection(intersection), _normal(normal)
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
