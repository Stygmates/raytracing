#ifndef __RAY_H
#define __RAY_H

#include "Vector.h"
#include <iostream>
#include <vector>


using namespace std;

/**
 * @brief The Ray class: defines the structure of a ray, it is composed of a source and a direction
 */
class Ray
{
	public:
		Ray();

        /**
         * @brief Ray
         * @param source A point origin of the ray
         * @param direction A vector direction of the ray
         */
		Ray(Point source, Vector direction);
		~Ray();


        /**
         * @brief get_source
         * @return The origin of the ray
         */
		Point get_source();
        /**
         * @brief get_direction
         * @return The vector direction of the ray
         */
		Vector get_direction();

        /**
         * @brief get_point_at_parameter
         * @param t
         * @return The point at a distance t from the origin
         */
        Point get_point_at_parameter(double t);

        /**
         * @brief set_source Sets the origin of the ray to source
         * @param source The new origin
         */
		void set_source(Point source);

        /**
         * @brief set_direction Sets the direction of the ray to direction
         * @param direction
         */
		void set_direction(Vector direction);

        /**
         * @brief stochastic_sampling
         * @param n
         * @return
         */
        vector<Point> stochastic_sampling(int n);

        /**
         * @brief translate_ray_to_screen
         */
        void translate_ray_to_screen();
        /**
         * @brief ray_unit
         */
        void ray_unit();

	private:
		Point _source;
		Vector _direction;
};

inline ostream& operator<<(ostream& flux,Ray r)
{
	flux <<"source :\n"<<r.get_source()<<"direction :\n"<<r.get_direction();

	return flux;
}

#endif
