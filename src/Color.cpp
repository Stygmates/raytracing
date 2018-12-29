#include "Color.h"
#include <iostream>
#include <cassert>
using namespace std;

Color::Color():_red(0.f), _green(0.f), _blue(0.f)
{

}

Color::Color(float red, float green, float blue): _red(red), _green(green), _blue(blue)
{
    if(red < 0.f)   this->_red = 0.f;
    if(green < 0.f)   this->_green = 0.f;
    if(blue < 0.f)   this->_blue = 0.f;
    if(red > 1.f)   this->_red = 1.f;
    if(green > 1.f)   this->_green = 1.f;
    if(blue > 1.f)   this->_blue = 1.f;

}


float Color::get_red() const
{
    return this->_red;
}

float Color::get_green() const
{
    return this->_green;
}

float Color::get_blue() const
{
    return this->_blue;
}

void Color::set_red(float red)
{
    this->_red = red;
    if(red < 0.f)   this->_red = 0.f;
    if(red > 1.f)   this->_red = 1.f;
}

void Color::set_green(float green)
{
    this->_green = green;
    if(green < 0.f)   this->_green = 0.f;
    if(green > 1.f)   this->_green = 1.f;
}

void Color::set_blue(float blue)
{
    this->_blue = blue;
    if(blue < 0.f)   this->_blue = 0.f;
    if(blue > 1.f)   this->_blue = 1.f;
}
void Color::set_rgb(float red, float green, float blue)
{
    this->set_red(red);
    this->set_green(green);
    this->set_blue(blue);
}

Color Color::operator*(const float& t)
{
    Color result(this->get_red() * t, this->get_green() * t, this->get_blue() * t);
    return result;
}

Color Color::operator+(const Color& c)
{
    Color result(this->get_red() + c.get_red(), this->get_green() + c.get_green(), this->get_blue() + c.get_blue());
    return result;
}

Color Color::operator*(const Color& c)
{
    Color result(this->get_red() * c.get_red(), this->get_green() * c.get_green(), this->get_blue() * c.get_blue());
    return result;
}

bool Color::operator!=(Color c)
{
    return ((this->get_red() != c.get_red()) || (this->get_green() != c.get_green()) || (this->get_blue() != c.get_blue()));
}
