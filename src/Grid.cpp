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
                cout << slot_element.get_min_slot() << endl;
                if(slot_element.boundingbox_intersects(t))
                {
                    cout << "Intersection with box " << slot_element.get_min_slot() << endl;
                    slot_element.add_triangle(t);
                }
            }
        }
    }
}
