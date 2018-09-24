#ifndef __OCTREE_H
#define __OCTREE_H

#include <vector>

#include "Triangle.h"

class Octree
{
	private:
		Octree *_dad;
		Octree *_sons[8];
		std::vector<Triangle> _triangles;

	public:
		Octree();
		~Octree();

		Octree *get_dad();
		Octree *get_son(int id);

		Octree *set_dad(Octree *dad);
		Octree *set_son(Octree *son, int id);

		void add_triangle(Triangle triangle);
};

#endif
