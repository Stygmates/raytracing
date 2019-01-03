#include <gtest/gtest.h>
#include "../include/Slot.h"

TEST(Slot, SlotBoundingBoxIntersectsTriangleTest)
{
//    Point p1(0, 0, 0);
//    Point p2(5, -5, 13);
//    Point p3(-6, 6, 5);
//    Shape *t = new Triangle(p1, p2, p3);
//    Point slot_min(-1, -1, -1);
//    Point slot_max(5, 5, 5);

//    Slot s(slot_min, slot_max, Point(0, 0, 0));
//    cout << "Hello" << endl;
//    EXPECT_TRUE(s.boundingbox_intersects(t));
//    cout << "Hi" << endl;
//    Point slot2_min(3, 3, 3);
//    Point slot2_max(4, 4, 4);
//    Slot s2(slot2_min, slot2_max, Point(0, 0, 0));
//    EXPECT_TRUE(s2.boundingbox_intersects(t));

//    Point slot3_min(3, 3, 3);
//    Point slot3_max(15, 13, 19);
//    Slot s3(slot3_min, slot3_max, Point(0, 0, 0));
//    EXPECT_TRUE(s3.boundingbox_intersects(t));
}

TEST(Slot, SlotBoundingBoxDoesntIntersectTriangleTest)
{
//    Point p1(0, 0, 0);
//    Point p2(5, -5, 13);
//    Point p3(-6, 6, 5);
//    Shape *t = new Triangle(p1, p2, p3);
//    Point slot_min(20, 25, 32);
//    Point slot_max(21, 30, 55);
//    Slot g(slot_min, slot_max, Point(0, 0, 0));
//    EXPECT_FALSE(g.boundingbox_intersects(t));

//    Point slot2_min(-10, 3, 2);
//    Point slot2_max(-7, 30, 55);
//    Slot s2(slot2_min, slot2_max, Point(0, 0, 0));
//    EXPECT_FALSE(s2.boundingbox_intersects(t));
}
