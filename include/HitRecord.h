#ifndef __HITRECORD_H
#define __HITRECORD_H
#include "Vector.h"
#include "Material.h"

class HitRecord{
public:
    HitRecord();
    HitRecord(Point intersection, bool intersect);
    HitRecord(Point intersection, Vector normal, Material material, float distance);
    Point get_intersection();
    Vector get_normal();
    Material get_material();
    float get_distance();
    Color get_color(Color lightcolor, Point lightposition, Point originCamera);
    bool get_intersect();
    void set_intersect(bool intersect);

private:
    Point _intersection;
    Vector _normal;
    Material _material;
    float _distance;
    bool _intersect;
};

#endif
