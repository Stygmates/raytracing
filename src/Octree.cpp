#include <iostream>
#include "../include/Octree.h"

using namespace std;

Octree::Octree(): _dad(NULL), _sons({}), _center(Point()), _size(0)
{
	
}


Octree::Octree(Point center, int size): _dad(NULL), _sons({}), _center(center)
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
    Point triangle_min = triangle.get_min_bounding_box();
    Point triangle_max = triangle.get_max_bounding_box();
    Point bounding_box_min(this->get_center().get_x() - this->get_size(), this->get_center().get_y() - this->get_size(), this->get_center().get_z() - this->get_size());
    Point bounding_box_max(this->get_center().get_x() + this->get_size(), this->get_center().get_y() + this->get_size(), this->get_center().get_z() + this->get_size());
    return ((bounding_box_min.get_x() <= triangle_min.get_x()) && (triangle_min.get_x() <= bounding_box_max.get_x())) ||
           ((bounding_box_min.get_y() <= triangle_min.get_y()) && (triangle_min.get_y() <= bounding_box_max.get_y())) ||
           ((bounding_box_min.get_z() <= triangle_min.get_z()) && (triangle_min.get_z() <= bounding_box_max.get_z()));
}

void Octree::add_triangle(Triangle triangle)
{
}
