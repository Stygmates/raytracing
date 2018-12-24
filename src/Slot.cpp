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


Slot::Slot(Point min_slot, Point max_slot, std::vector<Shape*> shapes): Slot(min_slot, max_slot)
{
    for(auto s: shapes)
    {
        this->add_shape(s);
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

vector<Shape*> Slot::get_shape_list()
{
    return this->shape_list;
}

void Slot::set_max_slot(const Point &max_slot)
{
    _max_slot = max_slot;
}

void Slot::set_min_slot(const Point &min_slot)
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
