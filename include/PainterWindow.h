#ifndef __PAINTERWINDOW_H
#define __PAINTERWINDOW_H
#include <QWidget>
#include <QPainter>
#include <vector>
#include "Point.h"

class PainterWindow : public QWidget {

  public :
        void paintEvent(QPaintEvent* event);
        std::vector<std::vector<Point>> image;
};

#endif
