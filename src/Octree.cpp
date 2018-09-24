#include <iostream>
#include "../include/Octree.h"

using namespace std;

Octree::Octree(): dad(NULL)
{
	
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
		return this->_son[id];
	else
	{
		cerr << "Octree::get_son: Invalid son id" << endl;
		return NULL;
	}
}

void Octree::set_dad(Octree *dad)
{
	this->_dad = dad;
}

void set_son(Octree *son, int id)
{
	if(id >= 0 && id < 8)
		this->_sons[id] = son;
	else
	{
		cerr << "Octree::set_son: Invalid son id" << endl;
	}
}

void add_triangle(Triangle triangle)
{

}
