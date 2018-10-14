#include "../include/Triangle.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

Triangle::Triangle()
{

}

Triangle::Triangle(Point p1, Point p2, Point p3): _p1(p1), _p2(p2), _p3(p3)
{
	Vector v1(this->_p1,this->_p2);
	Vector v2(this->_p1,this->_p3);
	this->_normal = v1^v2;
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

Vector Triangle::get_normal()
{
	return this->_normal;
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

Vector Triangle::compute_normal()
{
	Vector v1(this->_p1,this->_p2);
	Vector v2(this->_p1,this->_p3);
	return v1^v2;
}

double Triangle::compute_D()
{
	Vector N = get_normal();
	
	return N.get_x()*this->_p1.get_x() 
	     + N.get_y()*this->_p1.get_y() 
	     + N.get_z()*this->_p1.get_z();
}

double Triangle::compute_t(Vector source,Ray r)
{
	Vector N = get_normal();
	cout<<"Normal \n"<<N;
	double D = compute_D();

	
	double t;
	if( N*r.get_direction() == 0.0)
		std::cout << "parallel"<<endl;
	
	t = -( (N*source -  D ) / (N*r.get_direction()) );
	if (t < 0) 
		cout <<"triangle is behind"<<endl;

	return t;
}
Point Triangle::ray_intersect(Ray r)
{	//A*x + B*y + C*z + D = 0 
	//A B C = Normal
	//D = distance from the origin (0,0,0)
	//D = N * P0 where P0 point of triangle 
	//Step 1 : Finding P
	//P = Source + t*Dir
	
	Point O(0,0,0);
	Point S = r.get_source();
	Vector source(O,S);
	double t = compute_t(source,r);
	
	Vector P = source +t*r.get_direction();
	Point p_intersect(P.get_x(),P.get_y(),P.get_z());
	std::cout<<p_intersect;
	
	return p_intersect;
}

Point Triangle::get_min_bounding_box()
{
	int min_x = min(min(this->get_p1().get_x(), this->get_p2().get_x()), this->get_p3().get_x());
	int min_y = min(min(this->get_p1().get_y(), this->get_p2().get_y()), this->get_p3().get_y());
	int min_z = min(min(this->get_p1().get_z(), this->get_p2().get_z()), this->get_p3().get_z());
	return Point(min_x, min_y, min_z);
}

Point Triangle::get_max_bounding_box()
{
	int max_x = max(max(this->get_p1().get_x(), this->get_p2().get_x()), this->get_p3().get_x());
	int max_y = max(max(this->get_p1().get_y(), this->get_p2().get_y()), this->get_p3().get_y());
	int max_z = max(max(this->get_p1().get_z(), this->get_p2().get_z()), this->get_p3().get_z());
	return Point(max_x, max_y, max_z);
}