#ifndef __RAY_H
#define __RAY_H

#include "Vector.h"
#include <iostream>

using namespace std;

class Ray
{
	public:
		Ray();
		Ray(Point source, Vector direction);
		~Ray();


		Point get_source();
		Vector get_direction();

        Point get_point_at_parameter(double t);

		void set_source(Point source);
		void set_direction(Vector direction);
	private:
		Point _source;
		Vector _direction;
};

inline ostream& operator<<(ostream& flux,Ray r)
{
	flux <<"source :\n"<<r.get_source()<<"direction :\n"<<r.get_direction();

	return flux;
}

#endif
