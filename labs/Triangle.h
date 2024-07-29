#pragma once
#include <string> 
#include <iostream>
#include "Dot.h"
using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(double sideA, double sideB, double sideC);
	Triangle(Dot* dot_one, Dot* dot_two, Dot* dot_three);
	void set_dot_one(Dot* dotOne);
	Dot get_dot_one();
	void set_dot_two(Dot* dotTwo);
	Dot get_dot_two();
	void set_dot_three(Dot* dotThree);
	Dot get_dot_three();
	double* create_masSide();
	void output_len_side();
	double calc_perimetr();
	double calc_square();
	void set_side_A(double sideA);
	double get_side_A();
	void set_side_B(double sideB);
	double get_side_B();
	void set_side_C(double sideC);
	double get_side_C();
	double calc_square(Triangle* triangle1);
	class TriangleError
	{
	public:
		TriangleError() : message("A triangle with these sides does not exist") { }
		void printMessage() const { cout << message << endl; }
	private:
		string message;
	};


private:
	double side_A;
	double side_B;
	double side_C;
	Dot* dot_one;
	Dot* dot_two;
	Dot* dot_three;
	double square;
};
