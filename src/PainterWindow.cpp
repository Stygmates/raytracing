#include "PainterWindow.h"
#include <QDebug>
#include <cassert>

using namespace std;

void PainterWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    if(this->image.size() != 0)
    {
        this->resize(this->image[0].size(), this->image.size());
        for(int j = (int)this->image.size() - 1; j>= 0; j--)
        {
            for(int i = 0; i < (int)this->image[j].size(); i++)
            {
                Point pixel = this->image[(int)this->image.size() - 1 - j][i];
                const QColor color(pixel.get_x(), pixel.get_y(), pixel.get_z());
                painter.setPen(color);
                painter.drawPoint(i, j);
            }
        }
    }
}
