#include "PainterWindow.h"
#include <QDebug>
#include <cassert>

using namespace std;

void PainterWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    if(this->image.size() != 0)
    {
        this->resize(this->image[0].size(), this->image.size());
        for(unsigned int j = this->image.size() - 1; j>= 0; j--)
        {
            for(unsigned int i = 0; i < this->image[j].size(); i++)
            {
                Point pixel = this->image[j][i];
                const QColor color(pixel.get_x(), pixel.get_y(), pixel.get_z());
                painter.setPen(color);
                painter.drawPoint(i, j);
            }
        }
    }
}
