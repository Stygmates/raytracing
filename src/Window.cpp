#include "Window.h"

GLWindow::GLWindow(QWidget *parent)
    : GLWidget(0, parent, "Raytracing")
{


}

void GLWindow::initializeGL()
{


    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    x = 0.0;
    y = 0.0;
    z = 0.0;

    r = 0.0;
    g = 0.0;
    b = 0.0;

    std::cout << "init" << x << y << z << std::endl;

}

void GLWindow::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //std::cout << "reseize" << x << y << z << std::endl;

}


void GLWindow::paintGL()
{
    glClear(/*GL_COLOR_BUFFER_BIT |*/ GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -105.0f);
    //glClearColor(r, g, b, 0.0f);
    for(int i = 0; i < color_row.size(); i++)
    {
        int w = color_row.size() / 2;
        glColor3ub(color_row[i].get_x(), color_row[i].get_y(), color_row[i].get_z());
        glBegin(GL_POINTS);
        glVertex3i(i-50, row_index - 50 , 0.0f);
        glEnd();
    }

}


