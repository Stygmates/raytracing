#include "../include/mainwindow.h"
#include "../include/Loader.h"
#include "../include/PhongColor.h"
#include "Sphere.h"

#include <omp.h>
#include <iostream>
#include <cassert>
#include <QDebug>

using namespace experimental;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->start = new QPushButton("Start raytracing");
    this->exit = new QPushButton("Exit");
    this->load_obj = new QPushButton("Load object");
    this->path_label = create_label(25, 150, "No Object");
    QWidget *mainwidget = new QWidget();

    load_obj->setFixedWidth(100);
    path_label->setFixedWidth(500);
    //Controls

    QGridLayout* parameter = new QGridLayout();


    parameter->addWidget(create_label(25, 150, "Phong parameters :"), 1, 0);

    parameter->addWidget(create_label(25, 150, "Specular ="), 2, 0);
    phong_specular = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_specular, 2, 1);
    parameter->addWidget(create_label(25, 150, "Ambient ="), 3, 0);
    phong_ambient = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_ambient, 3, 1);
    parameter->addWidget(create_label(25, 150, "Diffuse ="), 4, 0);

    phong_diffuse = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50);
    parameter->addWidget(phong_diffuse, 4, 1);

    parameter->addWidget(create_label(25, 150, "Camera Position:"), 5, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 6, 0);
    pos_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_x, 6, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 7, 0);
    pos_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_y, 7, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 8, 0);
    pos_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(pos_z, 8, 1);

    parameter->addWidget(create_label(25, 150, "Screen Position:"), 9, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 10, 0);
    screen_lower_corner_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(screen_lower_corner_x, 10, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 11, 0);
    screen_lower_corner_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(screen_lower_corner_y, 11, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 12, 0);
    screen_lower_corner_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(screen_lower_corner_z, 12, 1);

    parameter->addWidget(create_label(25, 150, "Light direction:"), 13, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 14, 0);
    light_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_x, 14, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 15, 0);
    light_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_y, 15, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 16, 0);
    light_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50);
    parameter->addWidget(light_z, 16, 1);

    parameter->addWidget(start,17, 0);
    parameter->addWidget(exit,17, 1);


    //Main image
    window = new PainterWindow();

    QHBoxLayout *mainlayout = new QHBoxLayout();
    QVBoxLayout *image_loader_layout = new QVBoxLayout();
    QGridLayout* loader_layout = new QGridLayout();

    loader_layout->addWidget(load_obj,0, 10);
    loader_layout->addWidget(path_label, 0, 0);

    image_loader_layout->addLayout(loader_layout);
    image_loader_layout->addWidget(window);

    mainlayout->addLayout(image_loader_layout);
    mainlayout->addLayout(parameter);

    mainwidget->setLayout(mainlayout);
    this->setCentralWidget(mainwidget);

    connect(start, SIGNAL(clicked()),this, SLOT(validerparametre()));
    connect(load_obj, SIGNAL(clicked()),this, SLOT(Load_obj()));
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

void MainWindow::Load_obj()

{
    path_to_obj = QFileDialog::getOpenFileName(this->load_obj, "Load an object", QString(), ".obj (*.obj)");
    loader_error(path_to_obj, QColor(0, 0, 0, 255));

}

void MainWindow::loader_error(const QString &text, const QColor &color) {
    QPalette palette = path_label->palette();
    QBrush brush(color);
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    path_label->setPalette(palette);
    path_label->setText(text);

}

//Slot
void MainWindow::validerparametre()
{

    if(pos_x->value() == screen_lower_corner_x->value() &&
            pos_y->value() == screen_lower_corner_y->value() &&
            pos_z->value() == screen_lower_corner_z->value())
    {
        loader_error(QString::fromStdString("Camera position can not be at the same coordinates as the screen position"), QColor(255, 255, 0));
        return;
    }
    int nx = 600;
    int ny = 300;

    std::ifstream infile(this->path_to_obj.toStdString());
    if(!infile.good())
    {

        loader_error(QString::fromStdString("Failed to open the file " + this->path_to_obj.toStdString()) , QColor(255, 0, 0, 255));
        cerr << "Failed to open the file " << this->path_to_obj.toStdString() << endl;
        return;
    }

    vector<Shape*> shapes;
    Loader l;
    l.import(this->path_to_obj.toStdString());
    l.loadData(shapes);
    Vector lower_left_corner(screen_lower_corner_x->value(), screen_lower_corner_y->value(), screen_lower_corner_z->value());
    Vector horizontal(4.0, 0.0, 0.0);
    Vector vertical(0.0, 2.0, 0.0);
    //Point origin(0.0, 0.0, 0.0);

//    Point p1(-2.f, 1.f, -2.f);
//    Point p2(0.f, 1.f, -2.f);
//    Point p3(-1.f, 0.f, -2.f);

//    Point p4 = p1 + Point(2.f, 0.f, 0.f);
//    Point p5 = p2 + Point(2.f, 0.f, 0.f);
//    Point p6 = p3 + Point(2.f, 0.f, 0.f);
//    vector<Triangle> triangles;
//    Triangle tri("T1", p1, p2, p3);
//    triangles.push_back(tri);
//    triangles.push_back(Triangle("T2", p4, p5, p6));
    Grid grid(Point(-7.f, -7.f, -7.f), Point(7.f, 7.f, 7.f), 1, 1, 1);
    std::cout << shapes.size() <<std::endl;

    grid.add_shapes(shapes);




    Point origin_camera(this->pos_x->value(), this->pos_y->value(), this->pos_z->value());

    paint_image(origin_camera, lower_left_corner, horizontal, vertical , nx, ny, grid);

}

Color MainWindow::color(Ray r, Grid grid)
{
    DDA dda;
//    cout << grid.get_min_grid() << endl;
    vector<Slot*>slots_to_visit = dda.Slots_visited(r, grid);
    for(auto slot: slots_to_visit)
    {
//        cout << "Ray source " << r.get_source() << " direction: " << r.get_direction() << " going through min = " << slot->get_min_slot() << endl;
        vector<Shape*> shapes = slot->get_shape_list();
        Point lightPosition(light_x->value(), light_y->value(), light_z->value());
        Color lightcolor(1.0f, 1.0f, 1.0f);
        float ambient = 0.9f;
        if(auto color = intersects(r, shapes, ambient, lightPosition, lightcolor))
        {
            Color col = color.value_or(Color());
//            qDebug() << "Color found and returned" << endl;
            return col;
    //        return 0.5*Vector(normal.get_x()+1., normal.get_y()+1., normal.get_z()+1.);
        }
    }
//    qDebug() << "No triangle found" << endl;
    Vector unit_direction = r.get_direction().unit();
    float t = 0.5*(unit_direction.get_y() + 1.0);
    Color background_color = (1-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
    return background_color;
}

void MainWindow::paint_image(Point origin, Vector lower_left_corner, Vector horizontal, Vector vertical, int width, int height, Grid grid)
{
    window->image = vector<vector<Point>>(height, vector<Point>(width));
#pragma omp parallel for
    for(int j = height-1; j>= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i)/float(width);
            float v = float(j)/float(height);
            Ray camera(origin, lower_left_corner + u*horizontal + v*vertical);
            Color col = color(camera, grid);

//            qDebug() << "Color returned:" << col.get_x();
            int r = int(255.99*col.get_red());
            int g = int(255.99*col.get_green());
            int b = int(255.99*col.get_blue());
            assert(r>=0 && r<256);
            assert(g>=0 && g<256);
            assert(b>=0 && b<256);
            window->image[j][i] = Point(r, g, b);
        }
    }
    window->update();
}

optional<Color> MainWindow::intersects(Ray r, vector<Shape*> shapes, float ambientStrength, Point lightPosition, Color lightcolor)
{
    for(Shape *s: shapes)
    {
        if(auto p = s->ray_intersect(r))
        {
//            PhongColor pc(t, p.value(), ambientStrength, lightPosition, lightcolor);
              PhongColor pc(p.value().get_intersection(), 1.f/*ka*/, 1.f/*kd*/, 1.f/*ks*/, lightPosition, p.value().get_normal().unit(), Point(r.get_direction().get_x(), r.get_direction().get_y(), r.get_direction().get_z()));
            return pc.get_color(Color(0.f, 0.0f, 0.0f));
        }
    }
    return {};
}

MainWindow::~MainWindow()
{
    delete ui;
}


