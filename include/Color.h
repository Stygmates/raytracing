#ifndef COLOR_H
#define COLOR_H
#include <iostream>


class Color
{
public:
    Color();
    Color(float red, float green, float blue);
    float get_red() const;
    float get_green() const;
    float get_blue() const;

    void set_red(float red);
    void set_green(float green);
    void set_blue(float blue);
    void set_rgb(float red, float green, float blue);
    Color operator*(const float& t);
    Color operator+(const Color& c);
    Color operator*(const Color& c);

private:
    float _red, _green, _blue;
};

inline Color operator*(const float& t, const Color& c)
{
    Color result(c.get_red() * t, c.get_green() * t, c.get_blue() * t);
    return result;
}


inline std::ostream& operator<<(std::ostream& flux, Color c)
{
    flux << "Color : ( " << c.get_red() << ", " << c.get_green() << ", " << c.get_blue() << ")";
    return flux;
}

#endif // COLOR_H
