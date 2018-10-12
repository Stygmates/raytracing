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
