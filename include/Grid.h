#ifndef __GRID_H
#define __GRID_H


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
    Grid(Point min_grid, Point max_grid, int step_x, int step_y, int step_z);
    void add_triangles(vector<Triangle> triangles);
    void add_triangle(Triangle t);

    string get_name();
    int get_step_x() const;
    int get_step_y() const;
    int get_step_z() const;

    void set_name(string name);
    void set_step_x(int step_x);
    void set_step_y(int step_y);
    void set_step_z(int step_z);

    Point get_min_grid() const;
    Point get_max_grid() const;

    void set_min_grid(const Point &min_grid);
    void set_max_grid(const Point &max_grid);

    Slot* get_slot(Point min_slot);

    std::vector<std::vector<std::vector<Slot*>>> get_slots();

private:
    std::vector<std::vector<std::vector<Slot*>>> _slots;
    Point _min_grid, _max_grid;
    int _step_x, _step_y, _step_z;
};

#endif // GRID_H
