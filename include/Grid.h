#ifndef GRID_H
#define GRID_H

#include <map>

#include "Point.h"
#include "Slot.h"

struct pointcomp {
  bool operator() (const Point& left_point, const Point& right_point) const
  {return left_point.get_x() < right_point.get_x() && left_point.get_y() < right_point.get_y() && left_point.get_z() < right_point.get_z();}
};

class Grid
{
public:
    Grid(Point min_grid, Point max_grid, int x, int y, int z);
    void add_triangle(Triangle t);
private:
    std::vector<std::vector<std::vector<Slot>>> _slots;
    Point _min_grid, _max_grid;
    int _step_x, _step_y, _step_z;
};

#endif // GRID_H
