#include "Point.h"
#include "Ray.h"


class Triangle
{
	public:
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
		~Triangle();

		Point get_p1();
		Point get_p2();
		Point get_p3();
		Vector get_normal();
		
		void set_p1(Point p1);
		void set_p2(Point p2);
		void set_p3(Point p3);
		
		Vector compute_normal();
		double compute_D();
		double compute_t(Vector source,Ray r);
		Point ray_intersect(Ray r);
		Point get_min_bounding_box();
		Point get_max_bounding_box();

	private:
		Point _p1, _p2, _p3;
		Vector _normal;
};
