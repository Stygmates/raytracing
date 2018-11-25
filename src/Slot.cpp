#include "../include/Slot.h"
#include <assert.h>

Slot::Slot()
{

}

Slot::Slot(Point min_slot, Point max_slot): _min_slot(min_slot), _max_slot(max_slot)
{
    assert(min_slot.get_x() <= max_slot.get_x());
    assert(min_slot.get_y() <= max_slot.get_y());
    assert(min_slot.get_z() <= max_slot.get_z());
}


Slot::Slot(Point min_slot, Point max_slot, std::vector<Triangle> triangles): Slot(min_slot, max_slot)
{
    for(Triangle t: triangles)
    {
        this->add_triangle(t);
    }
}

Point Slot::get_min_slot()
{
    return this->_min_slot;
}

Point Slot::get_max_slot()
{
    return this->_max_slot;
}

void Slot::set_max_slot(const Point &max_slot)
{
    _max_slot = max_slot;
}

void Slot::set_min_slot(const Point &min_slot)
{
    _min_slot = min_slot;
}

bool Slot::boundingbox_intersects(Triangle t)
{
    bool intersects = ( (this->_min_slot.get_x() <= t.get_max_bounding_box().get_x() && this->_max_slot.get_x() >= t.get_min_bounding_box().get_x()) &&
                        (this->_min_slot.get_y() <= t.get_max_bounding_box().get_y() && this->_max_slot.get_y() >= t.get_min_bounding_box().get_y()) &&
                        (this->_min_slot.get_z() <= t.get_max_bounding_box().get_z() && this->_max_slot.get_z() >= t.get_min_bounding_box().get_z()));
    return intersects;
}

void Slot::add_triangle(Triangle t)
{
    if(this->boundingbox_intersects(t))
        this->triangle_list.push_back(t);
}

bool Slot::point_inside(Point p)
{
    return  (p.get_x()>= this->_min_slot.get_x() && p.get_x() <= this->_max_slot.get_x()) &&
            (p.get_x()>= this->_min_slot.get_y() && p.get_y() <= this->_max_slot.get_y()) &&
            (p.get_x()>= this->_min_slot.get_z() && p.get_z() <= this->_max_slot.get_z());
}
