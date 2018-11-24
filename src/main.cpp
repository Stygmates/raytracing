#include <iostream>
#include <fstream>
#include <unistd.h>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"
#include "../include/Grid.h"

#include <gtest/gtest.h>

using namespace std;

Vector color(Ray r)
{
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    return (1-t)*Vector(1.0, 1.0, 1.0) + t*Vector(0.5, 0.7, 1.0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
    ofstream myfile;
    myfile.open("image.ppm");
    int nx = 200;
    int ny = 100;

    myfile << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    Vector lower_left_corner(-2.0, -1.0, -1.0);
    Vector horizontal(4.0, 0.0, 0.0);
    Vector vertical(0.0, 2.0, 0.0);
    Point origin(0.0, 0.0, 0.0);
    for(int i = ny-1; i>= 0; i--)
    {
        for(int j = 0; j < nx; j++)
        {
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical);
            Vector col = color(ray);
            int r = int(255.99*col.get_x());
            int g = int(255.99*col.get_y());
            int b = int(255.99*col.get_z());
            myfile << r << " " << g << " " << b << endl;
        }
    }

    myfile.close();

    Point min_grid(0, 0, 0);
    Point max_grid(10, 10, 10);
    int x = 10;
    int y = 10;
    int z = 10;

    Grid grid(min_grid, max_grid, x, y, z);
    Triangle t1(Point(0.1, 0.1, 0.1), Point(0.2, 0.2, 0.2), Point(0.3, 0.3, 0.3));
    grid.add_triangle(t1);
	return RUN_ALL_TESTS();
}
