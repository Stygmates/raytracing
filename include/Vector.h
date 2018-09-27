#ifndef __VECTOR_H
#define __VECTOR_H

#include "Point.h"
#include <iostream>

using namespace std;

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
		double operator*(const Vector& v);
		//Vector operator*(const double& t);
		Vector operator+(const Vector& v);
		
		
		
};

inline Vector operator*(const double& t,const Vector& v)
{
	Vector vec;
	vec.set_x(t*v.get_x());	
	vec.set_y(t*v.get_y());	
	vec.set_z(t*v.get_z());

	return vec;	
}

inline ostream& operator<<(ostream& flux,Vector v)
{
	flux <<"Vector : "<<v.get_x()<<endl;
	flux <<"	 "<<v.get_y()<<endl;
	flux <<"	 "<<v.get_z()<<endl;

	return flux;
}
#endif
