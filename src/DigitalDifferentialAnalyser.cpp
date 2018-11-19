#include<DigitalDifferentialAnalyser.h>

void DDA::find_visited_grids(Ray ray_normalized, Point hit_point, Vector cellIndex)
{
    Vector deltaT( (1 - hit_point.get_x()) / ray_normalized.get_direction().get_x(),
                   (1 - hit_point.get_y()) / ray_normalized.get_direction().get_y(),
                   (1 - hit_point.get_z()) / ray_normalized.get_direction().get_z());

    float t_x = deltaT.get_x();
    float t_y = deltaT.get_y();
    float t_z = deltaT.get_z();
    float t = 0;

    while(true){
        if(t_x <= t_y and t_x <= t_z){
            t = t_x;                // current t, next intersection with cell along ray
            t_x += deltaT.get_x();  // increment, next crossing along x
        }else if(t_y <= t_x and t_y <= t_z){
            t = t_y;
            t_y += deltaT.get_y(); // increment, next crossing along y
        }else{
            t = t_z;
            t_z += deltaT.get_z(); // increment, next crossing along z
        }

        if(t>10)break;

    }

//return all grid visited
}
