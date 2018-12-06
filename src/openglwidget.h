#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

 #include <QOpenGLWidget>

class OpenGLWidget : public QOpenGLWidget
{
public:
    OpenGLWidget();
protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();
};

#endif // OPENGLWIDGET_H
