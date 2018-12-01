#include <DigitalDifferentialAnalyser.h>
#include <cmath>
#include <vector>

using namespace std;

vector<Slot> DDA::find_visited_grids(Ray ray_normalized, Grid grid)
{
    ray_normalized.set_direction(Vector( (ray_normalized.get_direction().get_x()-ray_normalized.get_source().get_x())*grid.get_step_x()+ray_normalized.get_source().get_x(),
                                         (ray_normalized.get_direction().get_y()-ray_normalized.get_source().get_y())*grid.get_step_y()+ray_normalized.get_source().get_y(),
                                         (ray_normalized.get_direction().get_z()-ray_normalized.get_source().get_z())*grid.get_step_z()+ray_normalized.get_source().get_z()));

    Vector deltaT( (grid.get_step_x() - ray_normalized.get_source().get_x()) / ray_normalized.get_direction().get_x(),
                   (grid.get_step_y() - ray_normalized.get_source().get_y()) / ray_normalized.get_direction().get_y(),
                   (grid.get_step_z() - ray_normalized.get_source().get_z()) / ray_normalized.get_direction().get_z());



    float t_x = deltaT.get_x();
    float t_y = deltaT.get_y();
    float t_z = deltaT.get_z();
    float t = 0;

    Slot current_slot = find_slot(grid, ray_normalized);

    vector<Slot> path;
    path.push_back(current_slot);   //first slot

    while(current_slot.get_max_slot().get_x() < grid.get_max_grid().get_x() &&
          current_slot.get_max_slot().get_y() < grid.get_max_grid().get_y() &&
          current_slot.get_max_slot().get_z() < grid.get_max_grid().get_z()   )
    {


        if(fabs(t_x) <= fabs(t_y) and fabs(t_x) <= fabs(t_z)){
            t = t_x;                // current t, next intersection with cell along ray
            t_x += deltaT.get_x();  // increment, next crossing along x
            Point min(current_slot.get_min_slot().get_x() + grid.get_step_x(), current_slot.get_min_slot().get_y(), current_slot.get_min_slot().get_z());
            Point max(current_slot.get_max_slot().get_x() + grid.get_step_x(), current_slot.get_max_slot().get_y(), current_slot.get_max_slot().get_z());
            Slot slot(min, max);
            path.push_back(slot);   //next slot
            //std::cout<<"x"<<std::endl;
            current_slot.set_min_slot(min);
            current_slot.set_max_slot(max);

        }else if(fabs(t_y) <= fabs(t_x) and fabs(t_y) <= fabs(t_z)){
            t = t_y;
            t_y += deltaT.get_y(); // increment, next crossing along y
            Point min(current_slot.get_min_slot().get_x(), current_slot.get_min_slot().get_y() + grid.get_step_y(), current_slot.get_min_slot().get_z());
            Point max(current_slot.get_max_slot().get_x(), current_slot.get_max_slot().get_y() + grid.get_step_y(), current_slot.get_max_slot().get_z());
            Slot slot(min, max);
            path.push_back(slot);   //next slot
            //std::cout<<"y"<<t<<std::endl;
            current_slot.set_min_slot(min);
            current_slot.set_max_slot(max);
        }else{
            t = t_z;
            t_z += deltaT.get_z(); // increment, next crossing along z
            Point min(current_slot.get_min_slot().get_x(), current_slot.get_min_slot().get_y(), current_slot.get_min_slot().get_z() + grid.get_step_z());
            Point max(current_slot.get_max_slot().get_x(), current_slot.get_max_slot().get_y(), current_slot.get_max_slot().get_z() + grid.get_step_z());
            Slot slot(min, max);
            path.push_back(slot);   //next slot
            //std::cout<<"z"<<std::endl;
            current_slot.set_min_slot(min);
            current_slot.set_max_slot(max);
        }

    }

return path;
}


Slot DDA::find_slot(Grid grid, Ray ray_normalized)
{
    Point current_slot, min_slot;
    current_slot = ray_normalized.get_source() - grid.get_min_grid();

    int x = ((int)current_slot.get_x()/grid.get_step_x()) * grid.get_step_x();
    int y = ((int)current_slot.get_y()/grid.get_step_y()) * grid.get_step_y();
    int z = ((int)current_slot.get_z()/grid.get_step_z()) * grid.get_step_z();

    current_slot.set_x(x);
    current_slot.set_y(y);
    current_slot.set_z(z);

    min_slot = current_slot + grid.get_min_grid();
    Point max_slot(min_slot.get_x()+grid.get_step_x(), min_slot.get_y()+grid.get_step_y(), min_slot.get_z()+grid.get_step_z());

    Slot slot(min_slot, max_slot);
    return slot;
}

vector<Slot*> DDA::Slots_visited(Ray r, Grid grid){
    r.set_direction(Vector(r.get_direction().unit()));
    DDA scan;
    vector<Slot> path = scan.find_visited_grids(r, grid);
    vector<Slot*> ptr_slot;
    for (auto p: path)
                ptr_slot.push_back( grid.get_slot( p.get_min_slot() ) );
    return ptr_slot;
}
