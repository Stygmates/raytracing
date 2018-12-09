#include "GLWidget.h"

GLWidget::GLWidget(int framesPerSecond, QWidget *parent, char *name)
    : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
    if(framesPerSecond == 0)
        t_Timer = NULL;
    else
    {
        int seconde = 1000; // 1 seconde = 1000 ms
        int timerInterval = seconde / framesPerSecond;
        t_Timer = new QTimer(this);
        connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        t_Timer->start( timerInterval );
    }


}


void GLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
        case Qt::Key_Escape:
            close();
            break;
    }
}

void GLWidget::timeOutSlot()
{
}
