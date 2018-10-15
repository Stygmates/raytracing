#include <gtest/gtest.h>
#include "../include/Grid.h"

TEST(Grid, GridBoundingBoxIntersectsTriangleTest)
{
    Point p1(0, 0, 0);
    Point p2(5, -5, 13);
    Point p3(-6, 6, 5);
    Triangle t(p1, p2, p3);
    Point grid_min(-1, -1, -1);
    Point grid_max(5, 5, 5);
    Grid g(grid_min, grid_max);
    EXPECT_TRUE(g.boundingbox_intersects(t));

    Point grid2_min(3, 3, 3);
    Point grid2_max(4, 4, 4);
    Grid g2(grid2_min, grid2_max);
    EXPECT_TRUE(g2.boundingbox_intersects(t));

    Point grid3_min(3, 3, 3);
    Point grid3_max(15, 13, 19);
    Grid g3(grid3_min, grid3_max);
    EXPECT_TRUE(g3.boundingbox_intersects(t));
}

TEST(Grid, GridBoundingBoxDoesntIntersectTriangleTest)
{
    Point p1(0, 0, 0);
    Point p2(5, -5, 13);
    Point p3(-6, 6, 5);
    Triangle t(p1, p2, p3);
    Point grid_min(20, 25, 32);
    Point grid_max(21, 30, 55);
    Grid g(grid_min, grid_max);
    EXPECT_FALSE(g.boundingbox_intersects(t));

    Point grid2_min(-10, 3, 2);
    Point grid2_max(-7, 30, 55);
    Grid g2(grid2_min, grid2_max);
    EXPECT_FALSE(g2.boundingbox_intersects(t));
}
