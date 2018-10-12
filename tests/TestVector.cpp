#include <gtest/gtest.h>
#include "../include/Vector.h"
#include "math.h"


TEST(Vectors, NormVectorTest)
{
    Point p1;
    Point p2(2, 3, 4);
    Vector v(p1, p2);
    EXPECT_DOUBLE_EQ(v.norm(), sqrt(29));
}

TEST(Vectors, CrossVectorTest)
{
    Vector v1(5, -6, 3);
    Vector v2(-2, 7, 4);
    Vector v3 = v1^v2;
    EXPECT_EQ(v3.get_x(), -45);
    EXPECT_EQ(v3.get_y(), -26);
    EXPECT_EQ(v3.get_z(), 23);
}