#include <gtest/gtest.h>
#include "../include/Point.h"

TEST(PointEmptyConstructor, PointEmptyConstructorTest)
{
    Point p;
    ASSERT_EQ(p.get_x(), 0);
    ASSERT_EQ(p.get_y(), 0);
    ASSERT_EQ(p.get_z(), 0);
}
