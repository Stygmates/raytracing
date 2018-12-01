#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "Point.h"
#include "Ray.h"


class Triangle
{
	public:
		Triangle();
        Triangle(string name);
		Triangle(Point p1, Point p2, Point p3);
        Triangle(string name, Point p1, Point p2, Point p3);
		~Triangle();

        string get_name();
		Point get_p1();
		Point get_p2();
		Point get_p3();
        Vector get_normal();

        void set_name(string name);
		void set_p1(Point p1);
		void set_p2(Point p2);
		void set_p3(Point p3);
		
        Vector compute_normal();
        float distance_from_origin();
        float distance_originRay_plan(Vector source,Ray r);
        Point intersection_ray_plan(Ray r,float t);
        bool ray_intersect(Ray r);

		Point get_min_bounding_box();
		Point get_max_bounding_box();

    private:
        string _name;
        Point _p1, _p2, _p3;
        Vector _normal;

};

inline ostream& operator<<(ostream& flux, Triangle t)
{
    flux << "Triangle " << t.get_name() << " with points : ( " << t.get_p1() << ", " << t.get_p2() << ", " << t.get_p3() << ")";
    return flux;
}
#endif
