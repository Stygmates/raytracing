#ifndef __HITRECORD_H
#define __HITRECORD_H
#include "Vector.h"
#include "Material.h"

class HitRecord{
public:
    HitRecord(Point intersection, Vector normal, Material material, float distance);
    Point get_intersection();
    Vector get_normal();
    Material get_material();
    float get_distance();
    Color get_color(Color lightcolor, Point lightposition, Point originCamera);
private:
    Point _intersection;
    Vector _normal;
    Material _material;
    float _distance;
};

#endif
