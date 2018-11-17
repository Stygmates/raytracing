#ifndef __OCTREE_H
#define __OCTREE_H

#include <array>
#include <vector>

#include "Triangle.h"

class Octree
{
	private:
		Octree *_dad;
        std::array<Octree*, 8> _sons;
		std::vector<Triangle> _triangles;
		Point _center;
		int _size;

	public:
		Octree();
		Octree(Point center, int size);
		~Octree();

		Octree *get_dad();
		Octree *get_son(int id);
		Point get_center();
		int get_size();

		void set_dad(Octree *dad);
		void set_son(Octree *son, int id);
		void set_center(Point center);
		void set_size(int size);

		bool triangle_bounding_box_intersects(Triangle triangle);
        void add_triangle(/*Triangle triangle*/);
};

#endif
