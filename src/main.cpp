#include "mainwindow.h"

#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
	::testing::InitGoogleTest(&argc, argv);
    #ifdef QT_DEBUG
        cerr << "Debug version" << endl;
    #endif
    #ifndef QT_DEBUG
        cerr << "Release version" << endl;
        MainWindow m;
        m.show();
        a.exec();
    #endif

	return RUN_ALL_TESTS();
}
