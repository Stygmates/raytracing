#include "../include/Triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(Point p1, Point p2, Point p3): _p1(p1), _p2(p2), _p3(p3)
{

}

Triangle::~Triangle()
{

}

Point Triangle::get_p1()
{
	return this->_p1;
}

Point Triangle::get_p2()
{
	return this->_p2;
}

Point Triangle::get_p3()
{
	return this->_p3;
}

void Triangle::set_p1(Point p1)
{
	this->_p1 = p1;
}

void Triangle::set_p2(Point p2)
{
	this->_p2 = p2;
}

void Triangle::set_p3(Point p3)
{
	this->_p3 = p3;
}

Point Triangle::ray_intersect(Ray r)
{	//A*x + B*y + C*z + D = 0 
	//A B C = Normal
	//D = distance from the origin (0,0,0)
	//D = N * P0 where P0 point of triangle 
	//Step 1 : Finding P
	//P = Origin + t*Dir

	/*compute normal*/
	Vector v1(this->_p1,this->_p2);
	Vector v2(this->_p1,this->_p3);
	Vector N = v1^v2;
	/*compute D*/
	int D = N.get_x()*_p1.get_x() + N.get_y()*_p1.get_y() + N.get_z()*_p1.get_z();
 	/*compute t*/
	Point O(0,0,0);
	Point S = r.get_source();
	Vector source(O,S);
	int t = (N*source + D) / (N*r.get_direction());
	
	return Point();
}
