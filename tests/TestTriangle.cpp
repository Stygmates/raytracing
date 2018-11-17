#include <gtest/gtest.h>
#include "../include/Triangle.h"

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
    Point p1(-4., -1., 0.);
    Point p2( 2., -1., 0.);
    Point p3( 0.,  1., 0.);
    Point P;

    Triangle tr(p1, p2, p3);
    Point    origin(0., 0., 10.);
    Point    dir(0., 0., 9.);
    Vector   direction(origin, dir);
    Ray r(origin, direction);
    ASSERT_EQ(1, tr.ray_intersect(r));
    ASSERT_DOUBLE_EQ(P.get_x(),0.);
    ASSERT_DOUBLE_EQ(P.get_y(),0.);
    ASSERT_DOUBLE_EQ(P.get_z(),0.);
}

