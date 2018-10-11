#include <iostream>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"

#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	Point p0(-4,-1,-5);
	Point p1(-2,-1,-5);
	Point p2(-3,1,-5);
	cout <<p0<<p1<<p2;

	Triangle tr(p0,p1,p2);
	Point origin(0,0,10);
	Point dir(0,0,9);
	Vector direction(origin,dir);
	Ray r(origin,direction);
	cout<<r;
	tr.ray_intersect(r);

	cout << "Hello world" << endl;
	return RUN_ALL_TESTS();
}
