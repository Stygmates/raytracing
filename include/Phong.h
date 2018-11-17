#ifndef PHONG_H
#define PHONG_H

#include "Color.h"
#include "Triangle.h"
#include "Ray.h"

class Phong
{
public:
    Phong();
    Phong(Color ambient, float ambient_coeff, Color diffuse, float diffuse_coeff, Color specular, float specular_coeff, Triangle t, Ray lightsource, Ray origin, int alpha);
};

#endif // PHONG_H
