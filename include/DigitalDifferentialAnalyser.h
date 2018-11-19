#ifndef DDA_H
#define DDA_H
#include<vector>
#include<Grid.h>
#include<Ray.h>
#include<Vector.h>
class DDA{

private :
    vector<Grid> Grids_intersect;

public :
    void find_visited_grids(Ray ray_normalized, Point hit_point, Vector cellIndex);




};

#endif // DDA_H

