#include <iostream>
#include "../include/Ray.h"
#include "../include/Triangle.h"
#include "../include/Point.h"
#include "../include/Vector.h"

#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	cout << "Hello world" << endl;

	return RUN_ALL_TESTS();
}
