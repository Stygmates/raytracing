#ifndef __SHAPE_H
#define __SHAPE_H

#include <experimental/optional>
#include "HitRecord.h"
#include "Ray.h"

using namespace experimental;

class Shape
{
public:
    bool boundingbox_intersects(Shape *s);
    virtual optional<HitRecord> ray_intersect(Ray r) = 0;
    /**
     * @brief get_min_bounding_box
     * @return A point with each component being the minimum in each direction of the bounding box of the triangle
     */
    virtual Point get_min_bounding_box() = 0;
    /**
     * @brief get_max_bounding_box
     * @return A point with each component being the maximum in each direction of the bounding box of the triangle
     */
    virtual Point get_max_bounding_box() = 0;
};

#endif
