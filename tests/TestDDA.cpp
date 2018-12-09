#include <gtest/gtest.h>
#include "../include/DigitalDifferentialAnalyser.h"

TEST(DDA, DigitalDifferentialAnalyserTest)
{
    Point min_grid(-150, -150, -150);
    Point max_grid(150, 150, 150);
    int x = 20;
    int y = 20;
    int z = 20;

    Grid grid(min_grid, max_grid, x, y, z);

    Point pis(0, 100, -50);     //pixel in screen

    Vector direction(pis.get_x() + 0.5, pis.get_y() + 0.5, pis.get_z());
    Ray r(Point(0, 0, 0), direction);

    DDA scan;
    vector<Slot> path = scan.find_visited_grids(r, grid);

    ASSERT_EQ(path[0].get_min_slot().get_x(), -10);
    ASSERT_EQ(path[0].get_min_slot().get_y(), 90);
    ASSERT_EQ(path[0].get_min_slot().get_z(), -50);
}

