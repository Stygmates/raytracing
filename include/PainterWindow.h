#ifndef __PAINTERWINDOW_H
#define __PAINTERWINDOW_H
#include <QWidget>
#include <QPainter>
#include <vector>
#include "Point.h"

/**
 * @brief The PainterWindow class: defines a helper class that draws the output picture on the app
 */
class PainterWindow : public QWidget {

  public :
    /**
         * @brief paintEvent The function that is called when the image needs to be repainted
         * @param event The event that triggers the repaint
         */
        void paintEvent(QPaintEvent* event);
        /**
         * @brief image The image to repaint
         */
        std::vector<std::vector<Point>> image;
};

#endif
