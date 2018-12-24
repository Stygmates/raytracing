#ifndef __HITRECORD_H
#define __HITRECORD_H
#include "Vector.h"

class HitRecord{
public:
    HitRecord(Point intersection, Vector normal);
    Point get_intersection();
    Vector get_normal();
private:
    Point _intersection;
    Vector _normal;
};

#endif
