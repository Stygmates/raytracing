#ifndef DDA_H
#define DDA_H
#include<vector>
#include<Grid.h>
#include<Ray.h>
class DDA{

private :
    vector<Grid> Grids_intersect;

public :
    vector<Slot> find_visited_grids(Ray ray_normalized, Grid grid);
    Slot find_slot(Grid grid, Ray ray_normalized);
    std::vector<Slot*> Slots(Ray r, Grid grid);
    vector<Slot*> Slots_visited(Ray r, Grid grid);



};

#endif // DDA_H

