#include "../include/PhongColor.h"

using namespace std;

//PhongColor::PhongColor(Triangle t, Point intersection, float ambientStrength, Point lightPosition, Color lightcolor)
//{
//    _ambient_color = ambientStrength * lightcolor;
//    Vector norm = t.get_normal().unit();
//    Vector lightDir(intersection, lightPosition);
//    cout << intersection << endl;
//    Vector lightDirNorm = lightDir.unit();
//    float diff = max(norm * lightDirNorm, 0.0f);
//    _diffuse_color = diff * lightcolor;
//}

PhongColor::PhongColor(Point intersection, float ka, float kd, float ks, Point lightPosition,Vector N, Point originCamera)
{
    Color white(1.0f, 1.0f, 1.0f);
    Vector V(intersection, originCamera);
    Vector L(intersection, lightPosition);
    L = L.unit();
    V = V.unit();
    Vector R = (N * ((N*L) * 2) ) - L;

    _ambient_color  = white * ka;
    _diffuse_color  = white * kd * (L*N);
    _specular_color = white * ks * pow(R*V, 20);
}

Color PhongColor::get_color(Color triangleColor)
{
    Color c = (triangleColor + _ambient_color + _diffuse_color + _specular_color);
    std::cout << c <<std::endl;

    if(c.get_red()   < 0.f)     c.set_red(0.f);
    if(c.get_green() < 0.f)     c.set_green(0.f);
    if(c.get_blue()  < 0.f)     c.set_blue(0.f);

    if(c.get_red()   > 1.f)     c.set_red(1.f);
    if(c.get_green() > 1.f)     c.set_green(1.f);
    if(c.get_blue()  > 1.f)     c.set_blue(1.f);

    return  c;
}
//Color PhongColor::get_color(Color triangleColor)
//{
//    return (_ambient_color + _diffuse_color) * triangleColor;
//}
