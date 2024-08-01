#pragma once
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> // для алгоритма сортировки 
using namespace std;

class Point
{
	friend ostream& operator<< (ostream& out, const Point& point);
public:
	Point();
	Point(double x, double y);
	double distanceTo(Point point);
	bool operator < (Point point) {
		return this->distanceTo(Point(0, 0)) < point.distanceTo(Point(0, 0));
	}
	Point operator+ (const Point& point)
	{
		Point p(this->x + point.x, this->y + point.y);
		return p;
	}
	Point operator+ (const int x)
	{
		Point p(this->x + x, this->y);
		return p;
	}
	void operator+= (Point& point)
	{
		*this = *this + point;
	}

private:
	double x;
	double y;
};
