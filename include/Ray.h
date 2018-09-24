#ifndef __RAY_H
#define __RAY_H

#include "Vector.h"

class Ray
{
	public:
		Ray();
		Ray(Point source, Vector direction);
		~Ray();


		Point get_source();
		Vector get_direction();

		void set_source(Point source);
		void set_direction(Vector direction);
	private:
		Point source;
		Vector direction;
};

#endif
