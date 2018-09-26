#include <iostream>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"

using namespace std;

int main()
{
	Point p0(-1,-1,0);
	Point p1(1,-1,0);
	Point p2(0,1,0);
	Triangle tr(p0,p1,p2);

	cout << "Hello world" << endl;
	return 0;
}
