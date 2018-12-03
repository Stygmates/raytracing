#include <Window.h>

Window::Window() : QWidget()

{



}

Window::Window(int w, int h)
    : _w(w),_h(h)
{
    setFixedSize(_w, _h);


    b_exit = new QPushButton("Quit", this);

    QLabel *label = new QLabel() ;
    label->setPixmap(QPixmap("image.ppm"));

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(label);
    gridLayout->addWidget(b_exit, 0 ,1);

    this->setLayout(gridLayout);

    QObject::connect(b_exit, SIGNAL(clicked()), qApp, SLOT(quit()));

    this->show();
}




