#ifndef __GRID_H
#define __GRID_H

#include "../include/Point.h"

class Grid
{
    public:
        Grid();
        Grid(Point min_grid, Point max_grid);
    private:
        Point _min_grid;
        Point _max_grid;

};

#endif
