#include <iostream>
#include "../include/Octree.h"

using namespace std;

Octree::Octree(): _dad(NULL), _size(0), _center(Point())
{
	
}


Octree::Octree(Point center, int size): _dad(NULL), _center(center)
{
	if(size < 0)
	{
		cerr << "Invalid size" << size << endl;
		this->_size = 0;
	}
	else
	{
		this->_size = size;
	}
}

Octree::~Octree()
{

}

Octree* Octree::get_dad()
{
	return this->_dad;
}

Octree* Octree::get_son(int id)
{
	if(id >= 0 && id < 8)
		return this->_sons[id];
	else
	{
		cerr << "Octree::get_son: Invalid son id" << endl;
		return NULL;
	}
}

Point Octree::get_center()
{
	return this->_center;
}

int Octree::get_size()
{
	return this->_size;
}

void Octree::set_dad(Octree *dad)
{
	this->_dad = dad;
}

void Octree::set_son(Octree *son, int id)
{
	if(id >= 0 && id < 8)
		this->_sons[id] = son;
	else
	{
		cerr << "Octree::set_son: Invalid son id" << endl;
	}
}

bool Octree::triangle_bounding_box_intersects(Triangle triangle)
{

}

void Octree::add_triangle(Triangle triangle)
{

}
