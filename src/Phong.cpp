#include <cassert>
#include "../include/Phong.h"
#include <cmath>

Phong::Phong(Color ambient, float ambient_coeff, Color diffuse, float diffuse_coeff, Color specular, float specular_coeff, Triangle t, Ray lightsource, Ray origin, int alpha)
{
    assert(ambient_coeff >= 0);
    assert(ambient_coeff <= 1);
    assert(diffuse_coeff >= 0);
    assert(diffuse_coeff <= 1);
    assert(specular_coeff >= 0);
    assert(specular_coeff <= 1);
    Vector mirror_reflexion = 2*(t.get_normal() * lightsource.get_direction()) * t.get_normal() - lightsource.get_direction();
    Color ambient_intensity = ambient * ambient_coeff;
    Color diffuse_intensity = diffuse_coeff * diffuse * (lightsource.get_direction()*t.get_normal());
    Color specular_intensity = specular_coeff * specular * pow(mirror_reflexion * origin.get_direction(), alpha);
    Color total_intensity = ambient_intensity + diffuse_intensity + specular_intensity;
}
