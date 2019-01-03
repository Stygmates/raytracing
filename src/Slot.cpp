#include "../include/Slot.h"
#include <assert.h>

Slot::Slot()
{

}

Slot::Slot(Point min_slot, Point max_slot, Point index): _min_slot(min_slot), _max_slot(max_slot), _index_slot(index)
{
    assert(min_slot.get_x() <= max_slot.get_x());
    assert(min_slot.get_y() <= max_slot.get_y());
    assert(min_slot.get_z() <= max_slot.get_z());
//    std::cout << index << std::endl;
    assert(index.get_x() >= 0);
    assert(index.get_y() >= 0);
    assert(index.get_z() >= 0);
}


//Slot::Slot(Point min_slot, Point max_slot, std::vector<Shape*> shapes): Slot(min_slot, max_slot)
//{
//    for(auto s: shapes)
//    {
//        this->add_shape(s);
//    }
//}

Point Slot::get_min_slot() const
{
    return this->_min_slot;
}

Point Slot::get_max_slot() const
{
    return this->_max_slot;
}

vector<Shape*> Slot::get_shape_list()
{
    return this->shape_list;
}

void Slot::set_max_slot(Point max_slot)
{
    _max_slot = max_slot;
}

void Slot::set_min_slot(Point min_slot)
{
    _min_slot = min_slot;
}

bool Slot::boundingbox_intersects(Shape *s)
{
    bool intersects = ( (this->_min_slot.get_x() <= s->get_max_bounding_box().get_x() && this->_max_slot.get_x() >= s->get_min_bounding_box().get_x()) &&
                        (this->_min_slot.get_y() <= s->get_max_bounding_box().get_y() && this->_max_slot.get_y() >= s->get_min_bounding_box().get_y()) &&
                        (this->_min_slot.get_z() <= s->get_max_bounding_box().get_z() && this->_max_slot.get_z() >= s->get_min_bounding_box().get_z()));
    return intersects;
}

void Slot::add_shape(Shape *s)
{
    if(this->boundingbox_intersects(s))
        this->shape_list.push_back(s);
}

bool Slot::point_inside(Point p)
{
    return  (p.get_x()>= this->_min_slot.get_x() && p.get_x() <= this->_max_slot.get_x()) &&
            (p.get_x()>= this->_min_slot.get_y() && p.get_y() <= this->_max_slot.get_y()) &&
            (p.get_x()>= this->_min_slot.get_z() && p.get_z() <= this->_max_slot.get_z());
}

bool Slot::operator!=(Slot s)
{
    return (s.get_min_slot() != this->get_min_slot() || s.get_max_slot() != this->get_max_slot());
}

Point Slot::get_index_slot()
{
    return _index_slot;
}

void Slot::set_index_slot(Point index_slot)
{
    _index_slot = index_slot;
}


HitRecord Slot::intersect(Ray r) const
{
    Vector invdir;
    int sign[3];

    invdir.set_x( 1 / r.get_direction().get_x());
    invdir.set_y( 1 / r.get_direction().get_y());
    invdir.set_z( 1 / r.get_direction().get_z());
    sign[0] = (invdir.get_x() < 0);
    sign[1] = (invdir.get_y() < 0);
    sign[2] = (invdir.get_z() < 0);

    Point bounds[2];
    bounds[0] = this->get_min_slot();
    bounds[1] = this->get_max_slot();

    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin  = (bounds[sign[0]].get_x()   - r.get_source().get_x()) * invdir.get_x();
    tmax  = (bounds[1-sign[0]].get_x() - r.get_source().get_x()) * invdir.get_x();
    tymin = (bounds[sign[1]].get_y()   - r.get_source().get_y()) * invdir.get_y();
    tymax = (bounds[1-sign[1]].get_y() - r.get_source().get_y()) * invdir.get_y();

    if ((tmin > tymax) || (tymin > tmax))
        return HitRecord(Point(1000, 1000,1000), false);
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (bounds[sign[2]].get_z()   - r.get_source().get_z()) * invdir.get_z();
    tzmax = (bounds[1-sign[2]].get_z() - r.get_source().get_z()) * invdir.get_z();

    if ((tmin > tzmax) || (tzmin > tmax))
        return HitRecord(Point(1000, 1000,1000), false);
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;


    Point intersection(r.get_source().get_x() + tmin*r.get_direction().get_x(), r.get_source().get_y() + tmin*r.get_direction().get_y(), r.get_source().get_z() + tmin*r.get_direction().get_z() );


    return HitRecord(intersection, true);

}
