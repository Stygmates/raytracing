#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QObject>
#include<QMainWindow>

#include <iostream>


class Window : public QWidget
{
    Q_OBJECT

    public:
    Window();
    Window(int w, int h);


    private:
    int _w, _h;
    float _r, _v, _b;
    int _x, _y;
    QPushButton *b_exit;

};


#endif // WINDOW_H

