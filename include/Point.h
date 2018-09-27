#ifndef __POINT_H
#define __POINT_H
#include <iostream>

using namespace std;

class Point{
	public:
		Point();
		Point(int x, int y, int z);
		~Point();

		int get_x();
		int get_y();
		int get_z();

		void set_x(int x);
		void set_y(int y);
		void set_z(int z);
	private:
		int _x, _y, _z;
};
inline ostream& operator<<(ostream& flux,Point P)
{
	flux <<"Point : ( "<<P.get_x()<<", "<<P.get_y()<<", "<<P.get_z()<<")"<<std::endl;
	return flux;  
}
#endif
