#include <iostream>
#include <fstream>
#include <unistd.h>
#include <experimental/optional>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"
#include "../include/DigitalDifferentialAnalyser.h"
#include "../include/Grid.h"
#include "../include/Slot.h"
#include "../include/Window.h"
//#include <QApplication>

#include <gtest/gtest.h>

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
        return Vector(1.0f, 0.0f, 0.0f);
//        return 0.5*Vector(normal.get_x()+1., normal.get_y()+1., normal.get_z()+1.);
    }
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    return (1-t)*Vector(1.0, 1.0, 1.0) + t*Vector(0.5, 0.7, 1.0);
}

Vector color(Ray r, Grid grid)
{
    DDA dda;
    vector<Slot*>slots_to_visit = dda.Slots_visited(r, grid);
    for(auto slot: slots_to_visit)
    {
//        cout << "Ray source " << r.get_source() << " direction: " << r.get_direction() << " going through min = " << slot->get_min_slot() << endl;
        vector<Triangle> tri = slot->get_triangle_list();
        if(auto t = intersects(r,tri))
        {
            Vector normal = t.value_or(Triangle()).get_normal().unit();
            return Vector(1.0f, 0.0f, 0.0f);
    //        return 0.5*Vector(normal.get_x()+1., normal.get_y()+1., normal.get_z()+1.);
        }
    }
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    return (1-t)*Vector(1.0, 1.0, 1.0) + t*Vector(0.5, 0.7, 1.0);
}

void create_image(string filename, Point origin, Vector lower_left_corner, Vector horizontal, Vector vertical, int width, int height, Grid grid)
{
    ofstream myfile;
    myfile.open(filename);
    myfile << "P3" << endl << width << " " << height << endl << "255" << endl;
    for(int j = height-1; j>= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i)/float(width);
            float v = float(j)/float(height);
            Ray camera(origin, lower_left_corner + u*horizontal + v*vertical);
            Vector col = color(camera, grid);
            int r = int(255.99*col.get_x());
            int g = int(255.99*col.get_y());
            int b = int(255.99*col.get_z());
            myfile << r << " " << g << " " << b << endl;
        }
    }
    myfile.close();
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
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


//    Point p1(0., 1., -1.);
//    Point p2(2., 0., -1.);
//    Point p3(-2., 0., -1);
//    Point p4(0., -1., -1);
    Point p1(-2.f, 1.f, -2.f);
    Point p2(0.f, 1.f, -2.f);
    Point p3(-1.f, 0.f, -2.f);

    Point p4 = p1 + Point(2.f, 0.f, 0.f);
    Point p5 = p2 + Point(2.f, 0.f, 0.f);
    Point p6 = p3 + Point(2.f, 0.f, 0.f);
    vector<Triangle> triangles;
    Triangle tri("T1", p1, p2, p3);
    triangles.push_back(tri);
    triangles.push_back(Triangle("T2", p4, p5, p6));
    Grid grid(Point(-4.f, -2.f, -7.f), Point(4.f, 2.f, 1.f), 2, 2, 2);
    grid.add_triangles(triangles);

    create_image("image.ppm", origin, lower_left_corner, horizontal, vertical , nx, ny, grid);
    Window window(1100, 500);
    a.exec();

	return RUN_ALL_TESTS();
}
