#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <fstream>
#include <QFileDialog>

#include "ui_mainwindow.h"
#include "Vector.h"
#include "Grid.h"
#include "DigitalDifferentialAnalyser.h"
#include "Triangle.h"
#include "PainterWindow.h"
#include <experimental/optional>

using namespace experimental;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QLabel* create_label(int max_height, int max_width,QString name);
    QDoubleSpinBox* create_double_spin_box(float xRange, float yRange, float step, int max_height, int max_width);

    Vector color(Ray r, Grid grid);
    void paint_image(Point origin, Vector lower_left_corner, Vector horizontal, Vector vertical, int width, int height, Grid grid);
    optional<Triangle> intersects(Ray r, vector<Triangle> tri);


    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton* start;
    QPushButton* exit;
    QPushButton* load_obj;

    QLabel* path_label;

    QString path_to_obj;

    QDoubleSpinBox* pos_x;
    QDoubleSpinBox* pos_y;
    QDoubleSpinBox* pos_z;

    QDoubleSpinBox* phong_Kf;
    QDoubleSpinBox* phong_Ki;
    QDoubleSpinBox* phong_Ks;

    QDoubleSpinBox* light_x;
    QDoubleSpinBox* light_y;
    QDoubleSpinBox* light_z;
    PainterWindow * window;
public slots :
    void validerparametre();
    void Load_obj();




};

#endif // MAINWINDOW_H
