Triangle::Triangle()
{

}

Triangle::Triangle(Point p1, Point p2, Point p3): _p1(p1), _p2(p2), _p3(p3)
{

}

Triangle::~Triangle()
{

}

Point Triangle::get_p1()
{
	return this->_p1;
}

Point Triangle::get_p2()
{
	return this->_p2;
}

Point Triangle::get_p3()
{
	return this->_p3;
}

void Triangle::set_p1(Point p1)
{
	this->_p1 = p1;
}

void Triangle::set_p2(Point p2)
{
	this->_p2 = p2;
}

void Triangle::set_p3(Point p3)
{
	this->_p3 = p3;
}
