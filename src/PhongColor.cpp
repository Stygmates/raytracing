#include "../include/PhongColor.h"

using namespace std;

PhongColor::PhongColor(Triangle t, Point intersection, float ambientStrength, Point lightPosition, Color lightcolor)
{
    _ambient_color = ambientStrength * lightcolor;
    Vector norm = t.get_normal().unit();
    Vector lightDir(intersection, lightPosition);
    cout << intersection << endl;
    Vector lightDirNorm = lightDir.unit();
    float diff = max(norm * lightDirNorm, 0.0f);
    _diffuse_color = diff * lightcolor;
}

Color PhongColor::get_color(Color triangleColor)
{
    return (_ambient_color + _diffuse_color) * triangleColor;
}
