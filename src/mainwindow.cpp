#include "../include/mainwindow.h"

#include "openglwidget.h"

#include <iostream>
#include <cassert>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->start = new QPushButton("Start raytracing");
    this->exit = new QPushButton("Exit");
    QWidget *mainwidget = new QWidget();


    //Controls

    QGridLayout* parameter = new QGridLayout();

    parameter->addWidget(create_label(25, 150, "Phong parameter :"), 0, 0);

    parameter->addWidget(create_label(25, 150, "Phong specular coefficient ="), 1, 0);
    phong_Ks = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_Ks, 1, 1);
    parameter->addWidget(create_label(25, 150, "Phong Imbiant coefficient  ="), 2, 0);
    phong_Ki = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_Ki, 2, 1);
    parameter->addWidget(create_label(25, 150, "Phong Diffus coefficient   ="), 3, 0);
    phong_Kf = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_Kf, 3, 1);

    parameter->addWidget(create_label(25, 150, "Camera Position :"), 4, 0);

    parameter->addWidget(create_label(25, 150, "X ="), 5, 0);
    pos_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_x, 5, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 6, 0);
    pos_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_y, 6, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 7, 0);
    pos_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_z, 7, 1);

    parameter->addWidget(create_label(25, 150, "Light source position :"), 8, 0);

    parameter->addWidget(create_label(25, 150, "X ="), 9, 0);
    light_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_x, 9, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 10, 0);
    light_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_y, 10, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 11, 0);
    light_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_z, 11, 1);

    parameter->addWidget(start,12, 0);
    parameter->addWidget(exit,12, 1);

    //Main image
    window = new PainterWindow();

    QHBoxLayout *mainlayout = new QHBoxLayout();

    mainlayout->addWidget(window);
    mainlayout->addLayout(parameter);

    mainwidget->setLayout(mainlayout);
    this->setCentralWidget(mainwidget);

    connect(start, SIGNAL(clicked()),this, SLOT(validerparametre()));
    connect(exit, SIGNAL(clicked()),qApp, SLOT(quit()));
}

QLabel* MainWindow::create_label(int max_height, int max_width,QString name)
{
    QLabel *label = new QLabel(name);
    label->setMaximumHeight(max_height);
    label->setMaximumWidth(max_width);

    return label;
}

QDoubleSpinBox* MainWindow::create_double_spin_box(float xRange, float yRange, float step, int max_height, int max_width)
{

    QDoubleSpinBox* spin_box = new QDoubleSpinBox();
    spin_box->setMaximumWidth(max_width);
    spin_box->setMaximumHeight(max_height);
    spin_box->setRange(xRange , yRange);
    spin_box->setSingleStep(step);

    return spin_box;
}

//Slot
void MainWindow::validerparametre()
{

    std::cout << phong_Ks->value() << std::endl;
    std::cout << phong_Ki->value() << std::endl;
    std::cout << phong_Kf->value() << std::endl;

    std::cout << pos_x->value() << std::endl;
    std::cout << pos_y->value() << std::endl;
    std::cout << pos_z->value() << std::endl;

    std::cout << light_x->value() << std::endl;
    std::cout << light_y->value() << std::endl;
    std::cout << light_z->value() << std::endl;


    //First test

    int nx = 200;
    int ny = 100;
    image->resize(650,550);

    Vector lower_left_corner(-2.0, -1.0, -1.0);
    Vector horizontal(4.0, 0.0, 0.0);
    Vector vertical(0.0, 2.0, 0.0);
    Point origin(0.0, 0.0, 0.0);

    Point p1(-2.f, 1.f, -2.f);
    Point p2(0.f, 1.f, -2.f);
    Point p3(-1.f, 0.f, -2.f);

    Point p4 = p1 + Point(2.f, 0.f, 0.f);
    Point p5 = p2 + Point(2.f, 0.f, 0.f);
    Point p6 = p3 + Point(2.f, 0.f, 0.f);
    vector<Triangle> triangles;
    Triangle tri("T1", p1, p2, p3);
    triangles.push_back(tri);
    triangles.push_back(Triangle("T2", p4, p5, p6));
    Grid grid(Point(-4.f, -2.f, -7.f), Point(4.f, 2.f, 1.f), 2, 2, 2);
    grid.add_triangles(triangles);


    paint_image(origin, lower_left_corner, horizontal, vertical , nx, ny, grid);

}

Vector MainWindow::color(Ray r, Grid grid)
{
    DDA dda;
    vector<Slot*>slots_to_visit = dda.Slots_visited(r, grid);
    for(auto slot: slots_to_visit)
    {
//        cout << "Ray source " << r.get_source() << " direction: " << r.get_direction() << " going through min = " << slot->get_min_slot() << endl;
        vector<Triangle> tri = slot->get_triangle_list();
        if(auto t = intersects(r,tri))
        {
            Vector normal = t.value_or(Triangle()).get_normal().unit();
            return Vector(1.0f, 0.0f, 0.0f);
    //        return 0.5*Vector(normal.get_x()+1., normal.get_y()+1., normal.get_z()+1.);
        }
    }
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    return (1-t)*Vector(1.0, 1.0, 1.0) + t*Vector(0.5, 0.7, 1.0);
}

void MainWindow::paint_image(Point origin, Vector lower_left_corner, Vector horizontal, Vector vertical, int width, int height, Grid grid)
{
    window->image = vector<vector<Point>>(height, vector<Point>(width));
    for(int j = height-1; j>= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i)/float(width);
            float v = float(j)/float(height);
            Ray camera(origin, lower_left_corner + u*horizontal + v*vertical);
            Vector col = color(camera, grid);

//            qDebug() << "Color returned:" << col.get_x();
            int r = int(255.99*col.get_x());
            int g = int(255.99*col.get_y());
            int b = int(255.99*col.get_z());
            assert(r>=0 && r<256);
            assert(g>=0 && g<256);
            assert(b>=0 && b<256);
            window->image[j][i] = Point(r, g, b);
        }
    }
    window->update();
}

optional<Triangle> MainWindow::intersects(Ray r, vector<Triangle> tri)
{
    Point p;
    for(Triangle t: tri)
    {
        if(t.ray_intersect(r))
            return t;
    }
    return {};
}

MainWindow::~MainWindow()
{
    delete ui;
}


