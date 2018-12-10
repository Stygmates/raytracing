#ifndef COLOR_H
#define COLOR_H
#include <iostream>


class Color
{
public:
    /**
     * @brief Color Color constructor
     */
    Color();
    /**
     * @brief Color Color constructor
     * @param red red the value should be between 0 and 1
     * @param green green the value should be between 0 and 1
     * @param blue blue the value should be between 0 and 1
     */
    Color(float red, float green, float blue);

    /**
     * @brief get_red Getter
     * @return red, value between 0 and 1
     */
    float get_red() const;
    /**
     * @brief get_green Getter
     * @return green, value between 0 and 1
     */
    float get_green() const;
    /**
     * @brief get_blue Getter
     * @return blue, value between 0 and 1
     */
    float get_blue() const;

    /**
     * @brief set_red Setter
     * @param red
     */
    void set_red(float red);
    /**
     * @brief set_green setter
     * @param green
     */
    void set_green(float green);
    /**
     * @brief set_blue setter
     * @param blue
     */
    void set_blue(float blue);
    /**
     * @brief set_rgb Sets the three values at the same time
     * @param red
     * @param green
     * @param blue
     */
    void set_rgb(float red, float green, float blue);

    /**
     * @brief operator *
     * @param t
     * @return
     */
    Color operator*(const float& t);
    /**
     * @brief operator +
     * @param c
     * @return
     */
    Color operator+(const Color& c);
    /**
     * @brief operator *
     * @param c
     * @return
     */
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
