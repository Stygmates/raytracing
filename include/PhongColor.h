#ifndef __PHONGCOLOR_H
#define __PHONGCOLOR_H

#include "Triangle.h"
#include "Color.h"
#include <cmath>

/**
 * @brief The PhongColor class: Class helper the color of a triangle enlightened by a light from a certain position
 */
class PhongColor{
    public:

    /**
     * @brief PhongColor Color constructor, computes the values to return
     * @param t The triangle to extract the normal from
     * @param intersection The intersection between the light and the triangle
     * @param ambientStrength The strenght of the light
     * @param lightPosition The position of the light
     * @param lightcolor The color of the light
     */
    PhongColor(Triangle t, Point intersection, float ambientStrength, Point lightPosition, Color lightcolor);
    PhongColor(Point intersection, float ka, float kd, float ks, Point lightPosition,Vector N, Point originCamera);


    /**
     * @brief get_color Returns the computed color with triangleColor
     * @param triangleColor The color of the triangle
     * @return The color of the pixel
     */
    Color get_color(Color triangleColor);
    private:
    /**
         * @brief _ambient_color The ambient component in Phong
         */
        Color _ambient_color;
        /**
         * @brief _diffuse_color The diffuse component in Phong
         */
        Color _diffuse_color;
        /**
         * @brief _specular_color The specular component in Phong
         */
        Color _specular_color;
};

#endif
