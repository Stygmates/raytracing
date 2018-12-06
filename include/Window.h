#ifndef WINDOW_H
#define WINDOW_H

#include "GLWidget.h"
#include "GL/glu.h"
#include <iostream>



class GLWindow : public GLWidget
{
    Q_OBJECT
public:
    explicit GLWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    float x, y, z;
    float r, g, b;


};


#endif // WINDOW_H

