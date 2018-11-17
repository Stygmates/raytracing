#include "../include/Triangle.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <QDebug>


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


Vector Triangle::compute_normal()
{
    Vector v1(this->_p1,this->_p2);
    Vector v2(this->_p1,this->_p3);
    return v1^v2;
}

Vector Triangle::get_normal()
{
    return this->_normal;
}


void Triangle::set_p1(Point p1)
{
	this->_p1 = p1;
    this->_normal = compute_normal();
}

void Triangle::set_p2(Point p2)
{
	this->_p2 = p2;
    this->_normal = this->compute_normal();
}

void Triangle::set_p3(Point p3)
{
	this->_p3 = p3;
    this->_normal = this->compute_normal();
}

float Triangle::compute_D()
{
    Vector N = get_normal();

    return N.get_x()*this->_p1.get_x()
         + N.get_y()*this->_p1.get_y()
         + N.get_z()*this->_p1.get_z();
}

float Triangle::compute_t(Vector source,Ray r)
{
    Vector N = get_normal();
    float D = compute_D();


    float t;
    if( N*r.get_direction() == 0.0)
        qDebug("parallel");

    t = -( (N*source -  D ) / (N*r.get_direction()) );
    if (t < 0)
        qDebug("triangle is behind");

    return t;
}

bool Triangle::ray_intersect_plan(Ray r,Point& P)
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

    Vector V = source +t*r.get_direction();
    P = Point(V.get_x(),V.get_y(),V.get_z());

    return t >= 0;
}

bool Triangle::ray_intersect(Ray r,Point& P){

    bool intersect_plan = ray_intersect_plan(r,P);
    if(!intersect_plan)
        return false;
    else{
        return  (Vector(this->_p1,this->_p2)^Vector(this->_p1,P))*(Vector(this->_p1,P)^Vector(this->_p1,this->_p3)) >= 0  &&
                (Vector(this->_p2,this->_p1)^Vector(this->_p2,P))*(Vector(this->_p2,P)^Vector(this->_p2,this->_p3)) >= 0  &&
                (Vector(this->_p3,this->_p1)^Vector(this->_p3,P))*(Vector(this->_p3,P)^Vector(this->_p3,this->_p2)) >= 0 ;
    }
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
