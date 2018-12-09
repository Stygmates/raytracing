#include "PainterWindow.h"
#include <QDebug>

using namespace std;

void PainterWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    for(int j = this->image.size() - 1; j>= 0; j--)
    {
        for(int i = 0; i < this->image[j].size(); i++)
        {
            Point pixel = this->image[j][i];
            const QColor color(pixel.get_x(), pixel.get_y(), pixel.get_z());
            painter.setPen(color);
            painter.drawPoint(i, j);
        }
    }
    qDebug() << "Painting done" << endl;
}
