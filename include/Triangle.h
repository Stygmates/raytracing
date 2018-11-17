#include "Point.h"
#include "Ray.h"
#include "Color.h"


class Triangle
{
	public:
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
		~Triangle();

		Point get_p1();
		Point get_p2();
		Point get_p3();

        Vector compute_normal();
        Vector get_normal();

		void set_p1(Point p1);
		void set_p2(Point p2);
		void set_p3(Point p3);
		
        float distance_from_origin();
        float distance_originRay_plan(Vector source,Ray r);
        Point intersection_ray_plan(Ray r,float t);
        bool ray_intersect(Ray r);

		Point get_min_bounding_box();
		Point get_max_bounding_box();
        Color Phong(Color ambient, float ambient_coeff, Color diffuse, float diffuse_coeff, Color specular, float specular_coeff, Ray lightsource, Ray origin, int alpha);
        float Phong(float ambient, float ambient_coeff, float diffuse, float diffuse_coeff, float specular, float specular_coeff, Ray lightsource, Ray origin, int alpha);
	private:
        Point _p1, _p2, _p3;
        Vector _normal;

};
