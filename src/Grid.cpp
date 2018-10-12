#include "../include/Grid.h"
#include <assert.h>

Grid::Grid(Point min_grid, Point max_grid): _min_grid(min_grid), _max_grid(max_grid)
{
    assert(min_grid.get_x() <= max_grid.get_x());
    assert(min_grid.get_y() <= max_grid.get_y());
    assert(min_grid.get_z() <= max_grid.get_z());
}


Grid::Grid(Point min_grid, Point max_grid, std::vector<Triangle> triangles): Grid(min_grid, max_grid)
{
    for(Triangle t: triangles)
    {
        this->add_triangle(t);
    }
}

bool Grid::boundingbox_intersects(Triangle t)
{
    bool intersects = ( (this->_min_grid.get_x() <= t.get_max_bounding_box().get_x() && this->_max_grid.get_x() >= t.get_min_bounding_box().get_x()) &&
                        (this->_min_grid.get_y() <= t.get_max_bounding_box().get_y() && this->_max_grid.get_y() >= t.get_min_bounding_box().get_y()) &&
                        (this->_min_grid.get_z() <= t.get_max_bounding_box().get_z() && this->_max_grid.get_z() >= t.get_min_bounding_box().get_z()));
    return intersects;
}

void Grid::add_triangle(Triangle t)
{
    if(this->boundingbox_intersects(t))
        this->triangle_list.push_back(t);
}
