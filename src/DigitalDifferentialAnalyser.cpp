#include <DigitalDifferentialAnalyser.h>
#include <cmath>
#include <vector>
#include <QDebug>
#include <cassert>

using namespace std;


vector<Slot*> DDA::Slots_visited(Ray r, Grid grid){

    DDA scan;
    vector<Slot> path = scan.find_visited_grids(r, grid);
    vector<Slot*> ptr_slot;
    for (auto p: path)
    {
        ptr_slot.push_back( grid.get_slot( p.get_index_slot() ) );
    }
    return ptr_slot;
}

vector<Slot> DDA::find_visited_grids(Ray ray_normalized, Grid grid)
{
    Ray r = ray_normalized;
    ray_normalized.ray_unit();
    Vector rayDirection = ray_normalized.get_direction();
    Point rayOrigin = ray_normalized.get_source();

    Vector cellDimension(grid.get_step_x(), grid.get_step_y(), grid.get_step_z());
    Vector deltaT, nextCrossingT;
    Point rayOrigGrid = rayOrigin /*- grid.get_min_grid()*/;
    Point gridDimension = grid.get_max_grid() - grid.get_min_grid();
    float t_x, t_y, t_z;
    if (rayDirection.get_x() < 0) {
    deltaT.set_x( -gridDimension.get_x() / rayDirection.get_x());
    t_x = (int(rayOrigGrid.get_x() / cellDimension.get_x()) * cellDimension.get_x() - rayOrigGrid.get_x()) / rayDirection.get_x();
    }
    else {
    deltaT.set_x( gridDimension.get_x() / rayDirection.get_x());
    t_x = ((int(rayOrigGrid.get_x() / cellDimension.get_x()) + 1) * cellDimension.get_x() - rayOrigGrid.get_x()) / rayDirection.get_x();
    }

    if (rayDirection.get_y() < 0) {
    deltaT.set_y( -gridDimension.get_y() / rayDirection.get_y());
    t_y = (int(rayOrigGrid.get_y() / cellDimension.get_y()) * cellDimension.get_y() - rayOrigGrid.get_y()) / rayDirection.get_y();
    }
    else {
    deltaT.set_y( gridDimension.get_y() / rayDirection.get_y());
    t_y = ((int(rayOrigGrid.get_y() / cellDimension.get_y()) + 1) * cellDimension.get_y() - rayOrigGrid.get_y()) / rayDirection.get_y();
    }

    if (rayDirection.get_z() < 0) {
    deltaT.set_z( -gridDimension.get_z() / rayDirection .get_z());
    t_z = (int(rayOrigGrid.get_z() / cellDimension.get_z()) * cellDimension.get_z() - rayOrigGrid.get_z()) / rayDirection.get_z();
    }
    else {
    deltaT.set_z( gridDimension .get_z() / rayDirection .get_z());
    t_z = ((int(rayOrigGrid.get_z() / cellDimension.get_z()) + 1) * cellDimension.get_z() - rayOrigGrid.get_z()) / rayDirection.get_z();
    }

    float t = 0;

    Slot current_slot = find_first_slot(grid, ray_normalized);
    Point cellIndex = current_slot.get_min_slot();          // origin of the ray (cell index)

    vector<Slot> path;
    path.push_back(current_slot);

    static int par = 0;

    while (1) {
        if (t_x < t_y && t_x < t_z)
        {
            t = t_x; // current t, next intersection with cell along ray
            t_x += deltaT.get_x(); // increment, next crossing along x
            if (rayDirection.get_x() < 0)
                cellIndex.set_x(cellIndex.get_x() - grid.get_step_x());
            else
                cellIndex.set_x(cellIndex.get_x() + grid.get_step_x());
        }
        else if(t_y < t_x && t_y < t_z)
        {
            t = t_y;
            t_y += deltaT.get_y(); // increment, next crossing along y
            if (rayDirection.get_y() < 0)
                cellIndex.set_y(cellIndex.get_y() - grid.get_step_y());
            else
                cellIndex.set_y(cellIndex.get_y() + grid.get_step_y());
        }
        else
        {
            t = t_z;
            t_z += deltaT.get_z(); // increment, next crossing along y
            if (rayDirection.get_z() < 0)
                cellIndex.set_z(cellIndex.get_z() - grid.get_step_z());
            else
                cellIndex.set_z(cellIndex.get_z() + grid.get_step_z());

        }

        Point min = cellIndex;
        Point max = cellIndex + Point(grid.get_step_x(), grid.get_step_y(), grid.get_step_z());
        Point index;


    // if some condition is met break from the loop
    if(!(max.get_x() <= grid.get_max_grid().get_x() &&
         max.get_y() <= grid.get_max_grid().get_y() &&
         max.get_z() <= grid.get_max_grid().get_z() &&
         min.get_x() >= grid.get_min_grid().get_x() &&
         min.get_y() >= grid.get_min_grid().get_y() &&
         min.get_z() >= grid.get_min_grid().get_z() )){
    break;
    }
    index.set_x((min.get_x() - grid.get_min_grid().get_x()) / grid.get_step_x());
    index.set_y((min.get_y() - grid.get_min_grid().get_y()) / grid.get_step_y());
    index.set_z((min.get_z() - grid.get_min_grid().get_z()) / grid.get_step_z());
    Slot slot(min, max, index);
    path.push_back(slot);
    }
    return path;

}

Slot DDA::find_first_slot(Grid grid, Ray ray_normalized)
{
    for(int x = 0; x < grid.get_max_index_x(); x++)
        for(int y = 0; y < grid.get_max_index_y(); y++)
            for(int z = 0; z < grid.get_max_index_z(); z++)
        {
            Point p(x, y, z);
            Slot* slot = grid.get_slot(p);
            HitRecord hr = slot->intersect(ray_normalized);

            if (hr.get_intersect() && !(hr.get_intersection()*1000!=ray_normalized.get_source()*1000))
                return *slot;
        }
    assert(1==0);
}

