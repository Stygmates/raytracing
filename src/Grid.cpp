#include "Grid.h"
#include "Point.h"
#include <sstream>

Grid::Grid(Point min_grid, Point max_grid, int slot_number_x, int slot_number_y, int slot_number_z): _min_grid(min_grid), _max_grid(max_grid)
{
    if(min_grid.get_x() > max_grid.get_x() || min_grid.get_y() > max_grid.get_y())
        cerr << "The grid's minimum is higher than its maximum";
    int interval_x = max_grid.get_x() - min_grid.get_x();
    int interval_y = max_grid.get_y() - min_grid.get_y();
    int interval_z = max_grid.get_z() - min_grid.get_z();
    if((interval_x % slot_number_x != 0) || (interval_y % slot_number_y != 0) || (interval_z % slot_number_z != 0))
        cerr << "The number of slots must be a divisor of the interval";

    //Size of a slot
    this->_step_x = interval_x/slot_number_x;
    this->_step_y = interval_y/slot_number_y;
    this->_step_z = interval_z/slot_number_z;

    for(int current_z = min_grid.get_z(); current_z < max_grid.get_z(); current_z += this->_step_z)
    {
        vector<vector<Slot>>slot_xy;
        for(int current_y = min_grid.get_y(); current_y < max_grid.get_y(); current_y += this->_step_y)
        {
            vector<Slot> slot_x;
            for(int current_x = min_grid.get_x(); current_x < max_grid.get_x(); current_x += this->_step_x)
            {
                Point pmin(current_x, current_y, current_z);
                Point pmax(current_x + this->_step_x, current_y + this->_step_y, current_z + this->_step_z);
                slot_x.push_back(Slot(pmin, pmax));
            }
            slot_xy.push_back(slot_x);
        }
        this->_slots.push_back(slot_xy);
    }
}

void Grid::add_triangle(Triangle t)
{
    for(auto slot_z: this->_slots)
    {
        for(auto slot_row: slot_z)
        {
            for(auto slot_element: slot_row)
            {
                if(slot_element.boundingbox_intersects(t))
                {
                    slot_element.add_triangle(t);
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
