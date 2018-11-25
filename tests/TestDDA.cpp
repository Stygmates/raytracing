#include <gtest/gtest.h>
#include "../include/DigitalDifferentialAnalyser.h"

TEST(DDA, DigitalDifferentialAnalyserTest)
{
    Point min_grid(-150, -150, -150);
    Point max_grid(150, 150, 150);
    int x = 15;
    int y = 15;
    int z = 15;

    Grid grid(min_grid, max_grid, x, y, z);

    Point pis(0, 100, -50);     //pixel in screen

    Vector direction(pis.get_x() + 0.5, pis.get_y() + 0.5, pis.get_z());
    Ray r(Point(0, 0, 0), direction);
    r.set_direction(Vector(r.get_direction().unit() + direction));  //translate direction of normalized ray
    Ray r_normalized(Point(pis.get_x() + 0.5, pis.get_y() + 0.5, -50), r.get_direction());

    DDA scan;
    vector<Slot> path = scan.find_visited_grids(r_normalized, grid);

    ASSERT_EQ(path[0].get_min_slot().get_x(), -10);
    ASSERT_EQ(path[0].get_min_slot().get_y(), 90);
    ASSERT_EQ(path[0].get_min_slot().get_z(), -50);
}

