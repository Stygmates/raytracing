#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "Point.h"
#include "Ray.h"


/**
 * @brief The Triangle class: defines the structure of a triangle, a triangle is composed of three points p1, p2, p3
 */
class Triangle
{
	public:
		Triangle();

        /**
         * @brief Triangle A triangle with 3 points at (0.f, 0.f, 0.f)
         * @param name
         */
        Triangle(string name);
        /**
         * @brief Triangle A triangle is defined by its 3 points p1, p2 and p3, the direction of the normal depends of the order in which the points are given
         * @param p1
         * @param p2
         * @param p3
         */
		Triangle(Point p1, Point p2, Point p3);
        /**
         * @brief Triangle A triangle is defined by its 3 points p1, p2 and p3, the direction of the normal depends of the order in which the points are given
         * @param name
         * @param p1
         * @param p2
         * @param p3
         */
        Triangle(string name, Point p1, Point p2, Point p3);
		~Triangle();

        /**
         * @brief get_name Name getter
         * @return The name of the triangle
         */
        string get_name();
        /**
         * @brief get_p1 p1 getter
         * @return p1
         */
		Point get_p1();

        /**
         * @brief get_p2 p2 getter
         * @return p2
         */
		Point get_p2();

        /**
         * @brief get_p3 p3 getter
         * @return p3
         */
		Point get_p3();
        /**
         * @brief get_normal Returns the normal of the triangle, this vector is not normalized
         * @return
         */
        Vector get_normal();

        /**
         * @brief set_name Sets the name of the triangle to name
         * @param name The name to give to the triangle
         */
        void set_name(string name);

        /**
         * @brief set_p1 Sets the first point of the triangle to p1
         * @param p1 The new first point of the triangle
         */
		void set_p1(Point p1);

        /**
         * @brief set_p2 Sets the second point of the triangle to p2
         * @param p2 The new second point of the triangle
         */
		void set_p2(Point p2);

        /**
         * @brief set_p3 Sets the third point of the triangle to p3
         * @param p3 The new third point of the triangle
         */
		void set_p3(Point p3);
		
        /**
         * @brief compute_normal Helper funcion that computes the normal of the triangle
         * @return The normal of the triangle
         */
        Vector compute_normal();

        /**
         * @brief distance_from_origin
         * @return The distance from the origin
         */
        float distance_from_origin();

        /**
         * @brief distance_originRay_plan Returns the distance between the origin of the ray and the plan of the triangle
         * @param source
         * @param r
         * @return
         */
        float distance_originRay_plan(Vector source, Ray r);

        /**
         * @brief intersection_ray_plan
         * @param r
         * @param t
         * @return The intersection point at a distance t from the origin of the plan
         */
        Point intersection_ray_plan(Ray r,float t);

        /**
         * @brief ray_intersect Returns whether the ray intersects the triangle or not
         * @param r The ray to test
         * @return True if the ray intersects the triangle, False otherwise
         */
        bool ray_intersect(Ray r);

        /**
         * @brief get_min_bounding_box
         * @return A point with each component being the minimum in each direction of the bounding box of the triangle
         */
		Point get_min_bounding_box();
        /**
         * @brief get_max_bounding_box
         * @return A point with each component being the maximum in each direction of the bounding box of the triangle
         */
		Point get_max_bounding_box();

    private:

        /**
         * @brief _name The name of the triangle, not really needed but may be used for debugging purposes
         */
        string _name;

        /**
         * @brief _p1, _p2, _p3 The points of the triangle
         */
        Point _p1, _p2, _p3;

        /**
         * @brief _normal The normal of the triangle
         */
        Vector _normal;

};

inline ostream& operator<<(ostream& flux, Triangle t)
{
    flux << "Triangle " << t.get_name() << " with points : ( " << t.get_p1() << ", " << t.get_p2() << ", " << t.get_p3() << ")";
    return flux;
}
#endif
