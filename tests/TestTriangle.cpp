#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/HitRecord.h"

TEST(Triangle, TriangleBoundingBoxTest)
{
    Point p1(0, 0, 0);
    Point p2(5, -5, 13);
    Point p3(-6, 6, 4);
    Triangle t(p1, p2, p3);
    ASSERT_EQ(t.get_min_bounding_box().get_x(), -6);
    ASSERT_EQ(t.get_min_bounding_box().get_y(), -5);
    ASSERT_EQ(t.get_min_bounding_box().get_z(), 0);
}

TEST(Triangle, PointOfIntersectTriangleWithRay)
{
    Point p1(-4., -1., -10.);
    Point p2( 2., -1., -10.);
    Point p3( 0.,  1., -10.);
    Point P(-1, -1, -1);

    Triangle tr(p1, p2, p3);
    Point    origin(-4., -1., -1.);
    Point    dir(-4., -1., -2.);
    Vector   direction(origin, dir);
    Ray r(origin, direction);
    HitRecord hr;
    if(auto p = tr.ray_intersect(r))
    {
        hr = p.value();
    }
    P = hr.get_intersection();
    std::cout << P << std::endl;
    ASSERT_DOUBLE_EQ(P.get_x(),-4.);
    ASSERT_DOUBLE_EQ(P.get_y(),-1.);
    ASSERT_DOUBLE_EQ(P.get_z(),-10.);
}

