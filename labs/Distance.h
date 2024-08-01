#pragma once
#include "Time.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class Distance
{
	//friend Distance operator-(const Distance&, const Distance&);
	//friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
public:
	//Distance() : feet(0), inches(0.0) {}
	Distance() : feet(0), inches(0.0), MTF(3.280833F) {}
	//Distance(int ft, float in) : feet(ft), inches(in) {}
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	void getdist();
	void showdist();
	Distance operator+ (const Distance& d2)
	{
		int f = feet + d2.feet;
		float i = inches + d2.inches;
		if (i >= 12.0)
		{
			i -= 12.0;
			f++;
		}
		return Distance(f, i);
	}
	Distance operator- (const Distance& d2)
	{
		int f = 0; float i = 0;
		if (inches < d2.inches)
		{
			i = inches + 12 - d2.inches;
			f = feet - 1 - d2.feet;
		}
		else
		{
			i = inches - d2.inches;
			f = feet - d2.feet;
		}
		return Distance(f, i);
	}
	friend ostream& operator<<(ostream& out, const Distance& dist)
	{
		out << dist.feet << "\" - " << dist.inches << "\"\n";
		return out;
	}
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
	void operator= (Distance dist) {
		feet = dist.feet;
		inches = dist.inches;
	}

private:
	int feet;
	float inches;
	const float MTF;
};