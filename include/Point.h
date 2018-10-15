#ifndef __POINT_H
#define __POINT_H
#include <iostream>

using namespace std;

class Point{
	public:
		Point();
        Point(double x, double y, double z);
		~Point();

        Point operator=(const Point& p);

        double get_x() const;
        double get_y() const;
        double get_z() const;

        void set_x(double x);
        void set_y(double y);
        void set_z(double z);
	private:
		int _x, _y, _z;
};
inline ostream& operator<<(ostream& flux,Point P)
{
	flux <<"Point : ( "<<P.get_x()<<", "<<P.get_y()<<", "<<P.get_z()<<")"<<std::endl;
	return flux;  
}
#endif
