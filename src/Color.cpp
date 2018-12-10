#include "Color.h"
#include <iostream>
#include <cassert>
using namespace std;

Color::Color():_red(0.f), _green(0.f), _blue(0.f)
{

}

Color::Color(float red, float green, float blue): _red(red), _green(green), _blue(blue)
{
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
    assert(red >= 0.f);
    assert(red <= 1.f);
    this->_red = red;
}

void Color::set_green(float green)
{
    assert(green >= 0.f);
    assert(green <= 1.f);
    this->_green = green;
}

void Color::set_blue(float blue)
{
    assert(blue >= 0.f);
    assert(blue <= 1.f);
    this->_blue = blue;
}
void Color::set_rgb(float red, float green, float blue)
{
    assert(red >= 0.f);
    assert(red <= 1.f);
    assert(green >= 0.f);
    assert(green <= 1.f);
    assert(blue >= 0.f);
    assert(blue <= 1.f);
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
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
