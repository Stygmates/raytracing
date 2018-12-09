#ifndef WINDOW_H
#define WINDOW_H

#include "GLWidget.h"
#include "GL/glu.h"
#include <iostream>
#include <vector>
#include <Point.h>



class GLWindow : public GLWidget
{
    Q_OBJECT
public:
    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    std::vector<Point> color_row;
    int row_index;

};


#endif // WINDOW_H

