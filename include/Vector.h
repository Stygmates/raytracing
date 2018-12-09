#ifndef __VECTOR_H
#define __VECTOR_H

#include "Point.h"
#include <iostream>

using namespace std;

/**
 * @brief The Vector class: defines a 3d vector
 */
class Vector
{
	private:
        float _x, _y, _z;

	public:
		Vector();
        /**
         * @brief Vector Constructor with two points
         * @param p1
         * @param p2
         */
		Vector(Point p1, Point p2);
        /**
         * @brief Vector Constructor
         * @param x
         * @param y
         * @param z
         */
        Vector(float x, float y, float z);
		~Vector();

		
        /**
         * @brief set_x X setter
         * @param x
         */
        void set_x(float x);

        /**
         * @brief set_y Y setter
         * @param y
         */
        void set_y(float y);

        /**
         * @brief set_z Z setter
         * @param z
         */
        void set_z(float z);

        /**
         * @brief get_translation Translates a point by a vector
         * @param p
         * @return
         */
        Point get_translation(Point p);
		
        /**
         * @brief get_x X getter
         * @return x
         */
        float get_x() const;

        /**
         * @brief get_y Y getter
         * @return y
         */
        float get_y() const;

        /**
         * @brief get_z Z getter
         * @return z
         */
        float get_z() const;

        /**
         * @brief set_v Sets the vector to (x, y, z)
         * @param x x
         * @param y y
         * @param z z
         */
        void set_v(float x, float y, float z);

        /**
         * @brief norm Computes the norm of the vector
         * @return The norm of the vector
         */
        float norm();

        /**
         * @brief unit The unit vector of the vector
         * @return
         */
        Vector unit();

        /**
         * @brief operator = Assignment operator
         * @param v
         * @return
         */
		Vector operator=(const Vector& v);

        /**
         * @brief operator ^ The cross product between two vectors
         * @param v The second vector to compute the cross product with
         * @return The result of the cross product
         */
		Vector operator^(const Vector& v);

        /**
         * @brief operator * The dot product between two vectors
         * @param v The second vector to compute the dot product with
         * @return The result of the dot product
         */
        float operator*(const Vector& v);
		//Vector operator*(const double& t);

        /**
         * @brief operator + The addition between two vectors
         * @param v The second vector to compute the addition with
         * @return The result of the addition
         */
		Vector operator+(const Vector& v);
		
		
		
};

inline Vector operator*(const float& t,const Vector& v)
{
	Vector vec;
	vec.set_x(t*v.get_x());	
	vec.set_y(t*v.get_y());	
	vec.set_z(t*v.get_z());

	return vec;	
}

inline ostream& operator<<(ostream& flux,Vector v)
{
    flux <<"Vector : " << v.get_x() << ", " << v.get_y() << ", " << v.get_z();

	return flux;
}
#endif
