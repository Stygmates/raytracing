#include "Grid.h"
#include "Point.h"
#include <sstream>
#include <cassert>

Grid::Grid(Point min_grid, Point max_grid, int step_x, int step_y, int step_z): _min_grid(min_grid), _max_grid(max_grid), _step_x(step_x), _step_y(step_y), _step_z(step_z)
{

}

Grid::Grid(std::vector<Shape*> shapes,int max_index_x, int max_index_y, int max_index_z): _max_index_x(max_index_x), _max_index_y(max_index_y), _max_index_z(max_index_z)
{
    Point min_grid = shapes[0]->get_min_bounding_box();
    Point max_grid = shapes[0]->get_max_bounding_box();
    for(auto s : shapes)
    {
        Point min = s->get_min_bounding_box();
        Point max = s->get_max_bounding_box();
        if(min.get_x() < min_grid.get_x()) min_grid.set_x(min.get_x());
        if(min.get_y() < min_grid.get_y()) min_grid.set_y(min.get_y());
        if(min.get_z() < min_grid.get_z()) min_grid.set_z(min.get_z());

        if(max.get_x() > max_grid.get_x()) max_grid.set_x(max.get_x());
        if(max.get_y() > max_grid.get_y()) max_grid.set_y(max.get_y());
        if(max.get_z() > max_grid.get_z()) max_grid.set_z(max.get_z());
    }


    this->set_min_grid(min_grid);
    this->set_max_grid(max_grid);

    this->set_step_x((this->get_max_grid().get_x() - this->get_min_grid().get_x()) /(float) max_index_x);
    this->set_step_y((this->get_max_grid().get_y() - this->get_min_grid().get_y()) /(float) max_index_y);
    this->set_step_z((this->get_max_grid().get_z() - this->get_min_grid().get_z()) /(float) max_index_z);

    ///create the slots

    if(this->get_min_grid().get_x() > this->get_max_grid().get_x() || this->get_min_grid().get_y() > this->get_max_grid().get_y())
        cerr << "The grid's minimum is higher than its maximum";

    float interval_x = this->get_max_grid().get_x() - this->get_min_grid().get_x();
    float interval_y = this->get_max_grid().get_y() - this->get_min_grid().get_y();
    float interval_z = this->get_max_grid().get_z() - this->get_min_grid().get_z();

    for(int current_z = 0; current_z * this->get_step_z() < interval_z; current_z += 1)
    {
        vector<vector<Slot*>>slot_xy;
        for(int current_y = 0; current_y * this->get_step_y() < interval_y; current_y += 1)
        {
            vector<Slot*> slot_x;
            for(int current_x = 0; current_x * this->get_step_x() < interval_x; current_x += 1)
            {
                Point index(current_x, current_y, current_z);
                Point pmin(current_x*this->_step_x + this->get_min_grid().get_x() , current_y * this->_step_y + this->get_min_grid().get_y(), current_z * this->_step_z + this->get_min_grid().get_z());
                Point pmax(pmin.get_x() + this->_step_x, pmin.get_y() + this->_step_y, pmin.get_z() + this->_step_z);

                slot_x.push_back(new Slot(pmin, pmax, index));
            }
            slot_xy.push_back(slot_x);
        }
        this->_slots.push_back(slot_xy);
    }
}

int Grid::get_max_index_x()
{
    return _max_index_x;
}

void Grid::set_max_index_x(int max_index_x)
{
    _max_index_x = max_index_x;
}

void Grid::set_max_index_y(int max_index_y)
{
    _max_index_y = max_index_y;
}

int Grid::get_max_index_y()
{
    return _max_index_y;
}

int Grid::get_max_index_z()
{
    return _max_index_z;
}

void Grid::set_max_index_z(int max_index_z)
{
    _max_index_z = max_index_z;
}

void Grid::add_shapes(vector<Shape*> shapes)
{
    for(auto s: shapes)
        this->add_shape(s);
}

void Grid::add_shape(Shape* s)
{
    for(auto slot_z: this->_slots)
    {
        for(auto slot_row: slot_z)
        {
            for(auto slot_element: slot_row)
            {
                if(slot_element->boundingbox_intersects(s))
                {
                    slot_element->add_shape(s);
                }
            }
        }
    }
}

float Grid::get_step_x() const
{
    return _step_x;
}

float Grid::get_step_y() const
{
    return _step_y;
}

float Grid::get_step_z() const
{
    return _step_z;
}

void Grid::set_step_x(float step_x)
{
    _step_x = step_x;
}

void Grid::set_step_y(float step_y)
{
    _step_y = step_y;
}

void Grid::set_step_z(float step_z)
{
    _step_z = step_z;
}

Point Grid::get_min_grid() const
{
    return _min_grid;
}

Point Grid::get_max_grid() const
{
    return _max_grid;
}

void Grid::set_min_grid(const Point &min_grid)
{
    _min_grid = min_grid;
}



void Grid::set_max_grid(const Point &max_grid)
{
    _max_grid = max_grid;
}


vector<vector<vector<Slot*>>> Grid::get_slots()
{
    return _slots;
}

Slot* Grid::get_slot(Point index_slot)
{
    float x, y, z;
    x = index_slot.get_x();
    y = index_slot.get_y();
    z = index_slot.get_z();
    assert((_slots.size() == this->get_max_index_z()) && (_slots[z].size() == this->get_max_index_y()) && (_slots[z][y].size() == this->get_max_index_x()));

    assert(!(_slots[z][y][x]->get_index_slot() != index_slot));
    return _slots[index_slot.get_z()][index_slot.get_y()][index_slot.get_x()];
}

HitRecord Grid::intersect(Ray r) const
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
    bounds[0] = this->get_min_grid();
    bounds[1] = this->get_max_grid();

    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin  = (bounds[sign[0]].get_x()   - r.get_source().get_x()) * invdir.get_x();
    tmax  = (bounds[1-sign[0]].get_x() - r.get_source().get_x()) * invdir.get_x();
    tymin = (bounds[sign[1]].get_y()   - r.get_source().get_y()) * invdir.get_y();
    tymax = (bounds[1-sign[1]].get_y() - r.get_source().get_y()) * invdir.get_y();

    if ((tmin > tymax) || (tymin > tmax))
        return HitRecord(Point(), false);
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (bounds[sign[2]].get_z()   - r.get_source().get_z()) * invdir.get_z();
    tzmax = (bounds[1-sign[2]].get_z() - r.get_source().get_z()) * invdir.get_z();

    if ((tmin > tzmax) || (tzmin > tmax))
        return HitRecord(Point(), false);
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    Point intersection(r.get_source().get_x() + tmin*r.get_direction().get_x(), r.get_source().get_y() + tmin*r.get_direction().get_y(), r.get_source().get_z() + tmin*r.get_direction().get_z() );


    return HitRecord(intersection, true);

}



