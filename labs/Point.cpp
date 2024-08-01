#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>
#include "Point.h"
using namespace std;

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::distanceTo(Point point)
{
	return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
}

ostream& operator<<(ostream& out, const Point& point)
{
	out << "x: " << point.x << " y: " << point.y << "\"\n";
	return out;
}
