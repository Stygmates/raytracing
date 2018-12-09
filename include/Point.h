#ifndef __POINT_H
#define __POINT_H
#include <iostream>

using namespace std;


/**
 * @brief The Point class: defines the structure of a point
 */
class Point{
	public:
		Point();

        /**
         * @brief Point
         * @param x
         * @param y
         * @param z
         */
        Point(float x, float y, float z);
		~Point();

        /**
         * @brief get_x x getter
         * @return x
         */
        float get_x() const;

        /**
         * @brief get_y y getter
         * @return y
         */
        float get_y() const;

        /**
         * @brief get_z z getter
         * @return z
         */
        float get_z() const;

        /**
         * @brief set_x x setter
         * @param x
         */
        void set_x(float x);

        /**
         * @brief set_y y setter
         * @param y
         */
        void set_y(float y);

        /**
         * @brief set_z z setter
         * @param z
         */
        void set_z(float z);

        /**
         * @brief operator + Addition between two points
         * @param v
         * @return
         */
        Point operator+(const Point& v);

        /**
         * @brief operator - Substraction between two points
         * @param v
         * @return
         */
        Point operator-(const Point& v);

        /**
         * @brief operator != Points comparison
         * @param v
         * @return
         */
        bool operator!=(Point v);
	private:
        float _x, _y, _z;
};
inline ostream& operator<<(ostream& flux,Point P)
{
    flux << "Point : ( " << P.get_x() << ", " << P.get_y() << ", " << P.get_z() << ")";
	return flux;  
}
#endif
