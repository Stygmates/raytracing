#ifndef __SLOT_H
#define __SLOT_H

#include <vector>

#include "../include/Point.h"
#include "../include/Triangle.h"

/**
 * @brief The Slot class: defines a slot of a grid, it is defined by two points: the min and the max in earch direction
 */
class Slot
{
    public:
        Slot();
        /**
         * @brief Slot A slot is part of a Grid
         * @param min_slot The minimum in each direction of the slot
         * @param max_slot The maximum in each direction of the slot
         */
        Slot(Point min_slot, Point max_slot);

        /**
         * @brief Slot A slot is part of a Grid
         * @param min_slot The minimum in each direction of the slot
         * @param max_slot The maximum in each direction of the slot
         * @param triangles The triangles to test against the slot
         */
        Slot(Point min_slot, Point max_slot, std::vector<Shape*> shapes);

        /**
         * @brief get_min_slot Returns the minimum coordinates in each direction of the slot
         * @return
         */
        Point get_min_slot();

        /**
         * @brief get_max_slot Returns the maximum coordinates in each direction of the slot
         * @return
         */
        Point get_max_slot();

        /**
         * @brief get_shape_list Returns the list of the shapes that intersect the current slot
         * @return
         */
        std::vector<Shape*> get_shape_list();

        /**
         * @brief set_min_slot Sets the slot maximum to min_slot
         * @param min_slot
         */
        void set_min_slot(const Point &min_slot);

        /**
         * @brief set_max_slot Sets the slot maximum to max_slot
         * @param max_slot
         */
        void set_max_slot(const Point &max_slot);

        /**
         * @brief boundingbox_intersects Checks if the boundingbox of the current slot intersects the boundingbox of the shape
         * @param s The shape to test
         * @return
         */
        bool boundingbox_intersects(Shape *s);

        /**
         * @brief add_triangle Adds a triangle to the slot, using @ref boundingbox_intersects(Triangle)
         * @param t The triangle to add
         */
        void add_shape(Shape *s);

        /**
         * @brief point_inside Tells if the coordinates of the point are inside the slot or not
         * @param p The point to test
         * @return True if the point is inside the slot and False otherwise
         */
        bool point_inside(Point p);

        /**
         * @brief operator != Comparison operator
         * @param s The second slot to compare
         * @return True if the slots are the same and false otherwise
         */
        bool operator!=(Slot s);


    private:
        /**
         * @brief _min_slot The point containing the minimum in each direction of the slot
         */
        Point _min_slot;

        /**
         * @brief _min_slot The point containing the maximum in each direction of the slot
         */
        Point _max_slot;

        /**
         * @brief triangle_list The triangles that have been added to the slot
         */
        std::vector<Shape*> shape_list;

};

#endif
