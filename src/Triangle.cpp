#include "../include/Triangle.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <QDebug>


using namespace std;

Triangle::Triangle(): _name("Triangle")
{

}

Triangle::Triangle(string name): _name(name)
{

}

Triangle::Triangle(Point p1, Point p2, Point p3): _p1(p1), _p2(p2), _p3(p3)
{
    Vector v1(this->_p1,this->_p2);
    Vector v2(this->_p1,this->_p3);
    this->_normal = v1^v2;
}

Triangle::Triangle(string name, Point p1, Point p2, Point p3): _name(name), _p1(p1), _p2(p2), _p3(p3)
{
    Vector v1(this->_p1,this->_p2);
    Vector v2(this->_p1,this->_p3);
    this->_normal = v1^v2;
}

Triangle::~Triangle()
{

}

string Triangle::get_name()
{
    return this->_name;
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

float Triangle::distance_from_origin()
{
    Vector N = get_normal();

    return N.get_x()*this->_p1.get_x()
         + N.get_y()*this->_p1.get_y()
         + N.get_z()*this->_p1.get_z();
}

float Triangle::distance_originRay_plan(Vector source,Ray r)
{
    Vector N = get_normal();
    float D = distance_from_origin();


    float t;
    if( N*r.get_direction() == 0.0)
        qDebug("parallel");

    t = -( (N*source -  D ) / (N*r.get_direction()) );
    if (t < 0)
        qDebug("triangle is behind");

    return t;
}

Point Triangle::intersection_ray_plan(Ray r,float t)
{	//A*x + B*y + C*z + D = 0
    //A B C = Normal
    //D = distance from the origin (0,0,0)
    //D = N * P0 where P0 point of triangle
    //Step 1 : Finding P
    //P = Source + t*Dir

    Vector source(Point(0, 0, 0),r.get_source());
    Vector V = source +t*r.get_direction();         //Compute point of intersect with plan

    return Point(V.get_x(),V.get_y(),V.get_z());
}

bool Triangle::ray_intersect(Ray r){


    Vector source(Point(0, 0, 0),r.get_source());
    double t = distance_originRay_plan(source,r);

    Point P;

    if(t>=0){
        P = this->intersection_ray_plan(r,t);
    }
    else
        return false;           //ray is parallel or behind


   return  (Vector(this->_p1,this->_p2)^Vector(this->_p1,P))*(Vector(this->_p1,P)^Vector(this->_p1,this->_p3)) >= 0  &&
           (Vector(this->_p2,this->_p1)^Vector(this->_p2,P))*(Vector(this->_p2,P)^Vector(this->_p2,this->_p3)) >= 0  &&
           (Vector(this->_p3,this->_p1)^Vector(this->_p3,P))*(Vector(this->_p3,P)^Vector(this->_p3,this->_p2)) >= 0 ;

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
