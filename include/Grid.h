    #ifndef __GRID_H
#define __GRID_H

#include <vector>

#include "../include/Point.h"
#include "../include/Triangle.h"

class Grid
{
    public:
        Grid();
        Grid(Point min_grid, Point max_grid);
        Grid(Point min_grid, Point max_grid, std::vector<Triangle> triangles);
        bool boundingbox_intersects(Triangle t);
        void add_triangle(Triangle t);
        bool point_inside(Point p);
    private:
        Point _min_grid;
        Point _max_grid;
        std::vector<Triangle> triangle_list;

};

#endif
