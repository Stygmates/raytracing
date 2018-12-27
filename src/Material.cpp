#include "Material.h"
#include "Vector.h"
#include "HitRecord.h"
#include "math.h"

Material::Material(): _ambient(Color()), _diffuse(Color()), _specular(Color()), _shininess(0.f)
{
}

Material::Material(Color ambient, Color diffuse, Color specular, float shininess): _ambient(ambient), _diffuse(diffuse), _specular(specular), _shininess(shininess)
{
}

Color Material::get_ambient()
{
    return this->_ambient;
}

Color Material::get_diffuse()
{
    return this->_diffuse;
}

Color Material::get_specular()
{
    return this->_specular;
}

float Material::get_shininess()
{
    return this->_shininess;
}


Color Material::get_color(Point intersection, Vector normal, Color lightcolor, Point lightposition, float Ka, float Kd, float Ks, Point originCamera)
{
    Vector V(originCamera, intersection);
    Vector L(intersection, lightposition);
    L = L.unit();
    V = V.unit();
    Vector norm = normal.unit();
    Vector R = (norm.unit() * ((norm*L) * 2) ) - L;



    Color ambient = lightcolor * Ka;
    Color diffuse = lightcolor * Kd * (L*norm);
    Color specular = lightcolor * Ks * powf(max(R*V, 0.f), this->_shininess);
    return ambient + diffuse + specular;
}
