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
        Vector(float x, float y, float z);
		~Vector();

		
        void set_x(float x);
        void set_y(float y);
        void set_z(float z);

        //Gets the translation of a point by a vector
        Point get_translation(Point p);
		
        float get_x() const;
        float get_y() const;
        float get_z() const;

        void set_v(float x, float y, float z);
        float norm();
        Vector unit();
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
