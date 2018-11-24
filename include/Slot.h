#ifndef __SLOT_H
#define __SLOT_H

#include <vector>

#include "../include/Point.h"
#include "../include/Triangle.h"

class Slot
{
    public:
        Slot();
        Slot(Point min_slot, Point max_slot);
        Slot(Point min_slot, Point max_slot, std::vector<Triangle> triangles);

        Point get_min_slot();
        Point get_max_slot();

        bool boundingbox_intersects(Triangle t);
        void add_triangle(Triangle t);
        bool point_inside(Point p);
    private:
        Point _min_slot;
        Point _max_slot;
        std::vector<Triangle> triangle_list;

};

#endif
