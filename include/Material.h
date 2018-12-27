#ifndef __MATERIAL_H
#define __MATERIAL_H

#include "Color.h"
#include "Point.h"
#include "Vector.h"
#include <iostream>

class Material
{
public:
    Material();
    Material(Color ambient, Color diffuse, Color specular, float shininess);
    Color get_ambient();
    Color get_diffuse();
    Color get_specular();
    float get_shininess();
    Color get_color(Point intersection, Vector normal, Color lightcolor, Point lightposition, Point originCamera);

    Color get_color(Point intersection, Vector normal, Color lightcolor, Point lightposition, Point originCamera, Color Ka, Color Kd, Color Ks);
private:
    Color _ambient, _diffuse, _specular;
    float _shininess;
};

inline std::ostream& operator<<(std::ostream& flux, Material m)
{
    flux << "Ambient: " << m.get_ambient() << std::endl;
    flux << "Diffuse: " << m.get_diffuse() << std::endl;
    flux << "Specular: " << m.get_specular() << std::endl;
    flux << "Specular power: " << m.get_shininess();
    return flux;
}
#endif
