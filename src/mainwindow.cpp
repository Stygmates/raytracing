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


    parameter->addWidget(create_label(25, 150, "Camera Position:"), 1, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 2, 0);
    pos_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(pos_x, 2, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 3, 0);
    pos_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(pos_y, 3, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 4, 0);
    pos_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(pos_z, 4, 1);

    parameter->addWidget(create_label(25, 150, "Screen Position:"), 5, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 6, 0);
    screen_lower_corner_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, -2.f);
    parameter->addWidget(screen_lower_corner_x, 6, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 7, 0);
    screen_lower_corner_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(screen_lower_corner_y, 7, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 8, 0);
    screen_lower_corner_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, -1.f);
    parameter->addWidget(screen_lower_corner_z, 8, 1);

    parameter->addWidget(create_label(25, 150, "Light position:"), 9, 0);


    parameter->addWidget(create_label(25, 150, "X ="), 10, 0);
    light_x = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(light_x, 10, 1);
    parameter->addWidget(create_label(25, 150, "Y ="), 11, 0);
    light_y = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(light_y, 11, 1);
    parameter->addWidget(create_label(25, 150, "Z ="), 12, 0);
    light_z = create_double_spin_box(-1000.f, 1000.0f, 1.f, 25, 50, 0.f);
    parameter->addWidget(light_z, 12, 1);

    parameter->addWidget(create_label(25, 150, "Light color :"), 13, 0);

    parameter->addWidget(create_label(25, 150, "Red ="), 14, 0);
    red = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50, 1.f);
    parameter->addWidget(red, 14, 1);
    parameter->addWidget(create_label(25, 150, "Green ="), 15, 0);
    green = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50, 1.f);
    parameter->addWidget(green, 15, 1);
    parameter->addWidget(create_label(25, 150, "Blue ="), 16, 0);
    blue = create_double_spin_box(0.f, 1.0f, 0.1f, 25, 50, 1.f);
    parameter->addWidget(blue, 16, 1);

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

QDoubleSpinBox* MainWindow::create_double_spin_box(float xRange, float yRange, float step, int max_height, int max_width, float value)
{

    QDoubleSpinBox* spin_box = new QDoubleSpinBox();
    spin_box->setMaximumWidth(max_width);
    spin_box->setMaximumHeight(max_height);
    spin_box->setRange(xRange , yRange);
    spin_box->setSingleStep(step);
    spin_box->setValue(value);
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
    int ny = 600;

    std::ifstream infile(this->path_to_obj.toStdString());
    if(!infile.good())
    {

        loader_error(QString::fromStdString("Failed to open the file " + this->path_to_obj.toStdString()) , QColor(255, 0, 0, 255));
        cerr << "Failed to open the file " << this->path_to_obj.toStdString() << endl;
        return;
    }

    vector<Shape*> shapes;

//    Sphere *sphere = new Sphere(Point(0.f, 0.f, -1.f), 1.5f, Material());
//    shapes.push_back(sphere);
    Loader l;
    l.import(this->path_to_obj.toStdString());
    l.loadData(shapes);
    Vector lower_left_corner(screen_lower_corner_x->value(), screen_lower_corner_y->value(), screen_lower_corner_z->value());
    Vector horizontal(4.0, 0.0, 0.0);
    Vector vertical(0.0, 4.0, 0.0);

    std::cout << shapes.size() <<std::endl;

    Grid grid(shapes, 1, 1, 1);

    grid.add_shapes(shapes);
    std::cout << "triangle addded" << std::endl;

    Point origin_camera(this->pos_x->value(), this->pos_y->value(), this->pos_z->value());

    paint_image(origin_camera, lower_left_corner, horizontal, vertical , nx, ny, grid);

}

Color MainWindow::color(Ray r, Grid grid, Vector horizontal)
{
    DDA dda;
    vector<Slot*>slots_to_visit = dda.Slots_visited(r, grid);

    for(auto slot: slots_to_visit)
    {

        vector<Shape*> shapes = slot->get_shape_list();
        Point lightPosition(light_x->value(), light_y->value(), light_z->value());
        Color lightcolor(red->value(), green->value(), blue->value());
        if(auto color = intersects(r, shapes, lightPosition, lightcolor, horizontal))
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

    float alpha;
    alpha = 60.0 * M_PI / 180.0;
    Vector depth;
    float midlle_pixel_x = 0.5 / float(width);
    float midlle_pixel_y = 0.5 / float(height);
    depth.set_x(midlle_pixel_x);
    depth.set_y(midlle_pixel_y);
    depth.set_z(-1. * horizontal.get_x()/(2.*tan(alpha/2.)));

#pragma omp parallel for
    for(int j = height-1; j>= 0; j--)
    {
        for(int i = 0; i < width; i++)
        {
            float u = float(i)/float(width);
            float v = float(j)/float(height);



            Ray camera(origin, lower_left_corner + u*horizontal + v*vertical + depth);
            HitRecord b = grid.intersect(camera);
            if(b.get_intersect())
            {
                camera.set_source(b.get_intersection());
                Color col = color(camera, grid, horizontal);

    //            qDebug() << "Color returned:" << col.get_x();
                int r = int(255.99*col.get_red());
                int g = int(255.99*col.get_green());
                int b = int(255.99*col.get_blue());
                r = powf(r, 1/1.2);
                g = powf(g, 1/1.2);
                b = powf(b, 1/1.2);
                assert(r>=0 && r<256);
                assert(g>=0 && g<256);
                assert(b>=0 && b<256);
                window->image[j][i] = Point(r, g, b);
            }else
                window->image[j][i] = Point(0, 0, 0);
        }
    }
    window->update();
    cout << "Image refreshed" << endl;
}

optional<Color> MainWindow::intersects(Ray r, vector<Shape*> shapes, Point lightPosition, Color lightcolor,  Vector horizontal)
{
    Point originCamera(this->pos_x->value(), this->pos_y->value(), this->pos_z->value());
    Point screenPos(this->screen_lower_corner_x->value(), this->screen_lower_corner_y->value(), this->screen_lower_corner_z->value());
    vector<HitRecord> hr;
    int n = 4;
    int n_2 = pow(n, 2.0);
    vector<Point> stochastic_ray = r.stochastic_sampling(n, this->window->image[0].size()/horizontal.get_x() );
    Color final_color(0.f, 0.f, 0.f);
    bool inersect_one_time_at_least = false;
    vector<Point> lightsPosition;
    lightsPosition.push_back(lightPosition);

//    for(auto it : stochastic_ray)///
//    {///
//        r.set_direction(r.get_direction()+Vector(it.get_x(), it.get_y(), it.get_z()));///

        for(Shape *s: shapes)
        {
            if(auto p = s->ray_intersect(r))
            {
                hr.push_back(p.value());
            }
        }
        if(hr.size() == 0)
        {
            return {};
//            n_2--;///
        }
        else
        {
//            inersect_one_time_at_least = true;///
            HitRecord closest = hr[0];
            float distance_closest = hr[0].get_distance();
            for(auto hit: hr)
            {
                if(hit.get_distance() < closest.get_distance())
                {
                    closest = hit;
                    distance_closest = hit.get_distance();
                }
            }
            if(object_between_lightAndIntersection(lightsPosition, closest.get_intersection(), shapes))
//                final_color = final_color + Color();///
                return Color();
            else
                return closest.get_color(lightcolor, lightPosition, originCamera);
//            final_color = final_color + closest.get_color(lightcolor, lightPosition, originCamera);///
        }
//    }///
//    if(inersect_one_time_at_least)///
//        return final_color * (1.f/(float)n_2);///
//    else///
//        return {};///
}

bool MainWindow::object_between_lightAndIntersection(vector<Point> lights, Point intersection, vector<Shape*> shapes){
    float epsilon = 0.001;
    for(auto l : lights)
    {
        Vector dirLight(intersection, l);
        float normLight = dirLight.norm();
        Ray shadaw_ray(intersection, dirLight );
        for(auto s : shapes)
        {
            if(s->ray_intersect(shadaw_ray)){
                if(auto hr = s->ray_intersect(shadaw_ray))
                {
                    HitRecord hr1 = hr.value();
                    Point p = hr1.get_intersection();
                    float distance = hr1.get_distance();
                    if( distance > epsilon && normLight > distance )
                        return true;
                }
            }
        }
    }
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


