#include <gtest/gtest.h>
#include "../include/Point.h"

TEST(Point, PointEmptyConstructorTest)
{
    Point p;
    ASSERT_EQ(p.get_x(), 0);
    ASSERT_EQ(p.get_y(), 0);
    ASSERT_EQ(p.get_z(), 0);
}

TEST(Point, PointConstructorTest)
{
    Point p0(-4,-1,-5);
    ASSERT_EQ(p0.get_x(), -4);
    ASSERT_EQ(p0.get_y(), -1);
    ASSERT_EQ(p0.get_z(), -5);
}
