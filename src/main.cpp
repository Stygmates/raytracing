#include <iostream>
#include <fstream>
#include <unistd.h>
#include <experimental/optional>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"

#include <gtest/gtest.h>
#include <vector>

using namespace std;
using namespace experimental;

optional<Triangle>intersects(Ray r, vector<Triangle> tri)
{
    Point p;
    for(Triangle t: tri)
    {
        if(t.ray_intersect(r))
            return t;
    }
    return {};
}

Vector color(Ray r, vector<Triangle> tri)
{
    Point p;
    if(auto t = intersects(r,tri))
    {
        Vector normal = t.value_or(Triangle()).get_normal().unit();
        return 0.5*Vector(normal.get_x()+1., normal.get_y()+1., normal.get_z()+1.);
    }
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    return (1-t)*Vector(1.0, 1.0, 1.0) + t*Vector(0.5, 0.7, 1.0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
    ofstream myfile;
    myfile.open("image.ppm");
    int nx = 1000;
    int ny = 500;

    myfile << "P3" << endl << nx << " " << ny << endl << "255" << endl;

    Vector lower_left_corner(-2.0, -1.0, -1.0);
    Vector horizontal(4.0, 0.0, 0.0);
    Vector vertical(0.0, 2.0, 0.0);
    Point origin(0.0, 0.0, 0.0);
    Point p1(0., 1., -1.);
    Point p2(2., 0., -1.);
    Point p3(-2., 0., -1);
    Point p4(0., -1., -1);
    vector<Triangle> triangles;
    Triangle tri(p1, p2, p3);
    triangles.push_back(tri);
    Triangle tri2(p3, p2, p4);
    triangles.push_back(tri2);
    Ray camera(origin, lower_left_corner);

    for(int j = ny-1; j>= 0; j--)
    {
        for(int i = 0; i < nx; i++)
        {
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            Ray ray(origin, lower_left_corner + u*horizontal + v*vertical);
            Vector col = color(ray, triangles);
            int r = int(255.99*col.get_x());
            int g = int(255.99*col.get_y());
            int b = int(255.99*col.get_z());
            myfile << r << " " << g << " " << b << endl;
        }
    }
    cout << tri.Phong(0.1, 0.1, 0.2, 0.2, 0.3, 0.3, camera, camera, 0);
    myfile.close();
	return RUN_ALL_TESTS();
}
