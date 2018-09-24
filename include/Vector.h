#ifndef __VECTOR_H
#define __VECTOR_H

#include "Point.h"

class Vector
{
	private:
		Point _p1, _p2;

	public:
		Vector();
		Vector(Point p1, Point p2);
		~Vector();

		Point get_p1();
		Point get_p2();
	
		void set_p1(Point p1);
		void set_p2(Point p2);
};

#endif
