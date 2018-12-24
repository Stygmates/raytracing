#include "Grid.h"
#include "Point.h"
#include <sstream>
#include <cassert>

Grid::Grid(Point min_grid, Point max_grid, int step_x, int step_y, int step_z): _min_grid(min_grid), _max_grid(max_grid), _step_x(step_x), _step_y(step_y), _step_z(step_z)
{
    if(min_grid.get_x() > max_grid.get_x() || min_grid.get_y() > max_grid.get_y())
        cerr << "The grid's minimum is higher than its maximum";
    int interval_x = max_grid.get_x() - min_grid.get_x();
    int interval_y = max_grid.get_y() - min_grid.get_y();
    int interval_z = max_grid.get_z() - min_grid.get_z();
    if((interval_x % step_x != 0) || (interval_y % step_y != 0) || (interval_z % step_z != 0))
        cerr << "The number of slots must be a divisor of the interval";

    for(int current_z = min_grid.get_z(); current_z < max_grid.get_z(); current_z += this->_step_z)
    {
        vector<vector<Slot*>>slot_xy;
        for(int current_y = min_grid.get_y(); current_y < max_grid.get_y(); current_y += this->_step_y)
        {
            vector<Slot*> slot_x;
            for(int current_x = min_grid.get_x(); current_x < max_grid.get_x(); current_x += this->_step_x)
            {
                Point pmin(current_x, current_y, current_z);
                Point pmax(current_x + this->_step_x, current_y + this->_step_y, current_z + this->_step_z);
                slot_x.push_back(new Slot(pmin, pmax));
            }
            slot_xy.push_back(slot_x);
        }
        this->_slots.push_back(slot_xy);
    }
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

int Grid::get_step_x() const
{
    return _step_x;
}

int Grid::get_step_y() const
{
    return _step_y;
}

int Grid::get_step_z() const
{
    return _step_z;
}

void Grid::set_step_x(int step_x)
{
    _step_x = step_x;
}

void Grid::set_step_y(int step_y)
{
    _step_y = step_y;
}

void Grid::set_step_z(int step_z)
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

Slot* Grid::get_slot(Point min_slot)
{
    int x, y, z;
    x = (min_slot.get_x() - this->get_min_grid().get_x() )/this->get_step_x();
    y = (min_slot.get_y() - this->get_min_grid().get_y() )/this->get_step_y();
    z = (min_slot.get_z() - this->get_min_grid().get_z() )/this->get_step_z();
    assert(((int)_slots.size() > z) && ((int)_slots[z].size() > y) && ((int)_slots[z][y].size() > x));

    assert(!(_slots[z][y][x]->get_min_slot() != min_slot));
    return _slots[z][y][x];
}

