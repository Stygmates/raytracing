#ifndef __POINT_H
#define __POINT_H
#include <iostream>

using namespace std;

class Point{
	public:
		Point();
        Point(float x, float y, float z);
		~Point();

        float get_x();
        float get_y();
        float get_z();

        void set_x(float x);
        void set_y(float y);
        void set_z(float z);
	private:
        float _x, _y, _z;
};
inline ostream& operator<<(ostream& flux,Point P)
{
	flux <<"Point : ( "<<P.get_x()<<", "<<P.get_y()<<", "<<P.get_z()<<")"<<std::endl;
	return flux;  
}
#endif
