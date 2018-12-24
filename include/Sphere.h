#ifndef __SPHERE_H
#define __SPHERE_H

#include "Shape.h"
#include "HitRecord.h"

class Sphere: public Shape
{
public:
    Sphere();
    Sphere(Point center, float radius);
    /**
     * @brief ray_intersect Returns whether the ray intersects the triangle or not
     * @param r The ray to test
     * @return True if the ray intersects the triangle, False otherwise
    */
    optional<HitRecord> ray_intersect(Ray r);
    virtual Point get_min_bounding_box();
    virtual Point get_max_bounding_box();

private:
    Point _center;
    float _radius;
};

#endif
