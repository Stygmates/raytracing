#ifndef __PHONGCOLOR_H
#define __PHONGCOLOR_H

#include "Triangle.h"
#include "Color.h"

class PhongColor{
    public:

    PhongColor(Triangle t, Point intersection, float ambientStrength, Point lightPosition, Color lightcolor);
    Color get_color(Color triangleColor);
    private:
        Color _ambient_color;
        Color _diffuse_color;
};

#endif
