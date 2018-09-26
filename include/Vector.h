#ifndef __VECTOR_H
#define __VECTOR_H

#include "Point.h"

class Vector
{
	private:
		int _x, _y, _z;

	public:
		Vector();
		Vector(Point p1, Point p2);
		~Vector();

		
		void set_x(int x);
		void set_y(int y);
		void set_z(int z);
		
		int get_x() const;
		int get_y() const;
		int get_z() const;

		void set_v(int x,int y, int z);
		Vector operator=(const Vector& v);
		Vector operator^(const Vector& v);
		int operator*(const Vector& v);
		
		
};

#endif
