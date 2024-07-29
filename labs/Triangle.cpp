#include "Triangle.h"
#include "Dot.h"

Triangle::Triangle(double sideA, double sideB, double sideC)
{
	double Maximum = max(sideA, max(sideB, sideC));
	double Minimum = min(sideA, min(sideB, sideC));
	if ((2 * Maximum >= (sideA + sideB + sideC)) || (Minimum < 0))
		throw TriangleError();
	else
	{
		Triangle::set_side_A(sideA);
		Triangle::set_side_B(sideB);
		Triangle::set_side_C(sideC);
	}
}

void Triangle::set_side_A(double sideA)
{
	side_A = sideA;
}

double Triangle::get_side_A()
{
	return side_A;
}

void Triangle::set_side_B(double sideB)
{
	side_B = sideB;
}

double Triangle::get_side_B()
{
	return side_B;
}

void Triangle::set_side_C(double sideC)
{
	side_C = sideC;
}

double Triangle::get_side_C()
{
	return side_C;
}

double Triangle::calc_square(Triangle* triangle1)
{
	double square, pp;
	pp = (triangle1->get_side_A() + triangle1->get_side_B() + triangle1->get_side_C()) / 2;
	square = sqrt(pp * (pp - triangle1->get_side_A()) * (pp - triangle1->get_side_B()) * (pp - triangle1->get_side_C()));
	return square;
}

Triangle::Triangle()
{
	dot_one = new Dot();
	dot_two = new Dot(0, 3);
	dot_three = new Dot(4, 3);
}

Triangle::Triangle(Dot* dot_one, Dot* dot_two, Dot* dot_three)
{
	Triangle::set_dot_one(dot_one);
	Triangle::set_dot_two(dot_two);
	Triangle::set_dot_three(dot_three);
}

void Triangle::set_dot_one(Dot* dotOne)
{
	dot_one = dotOne;
}

Dot Triangle::get_dot_one()
{
	return *dot_one;
}

void Triangle::set_dot_two(Dot* dotTwo)
{
	dot_two = dotTwo;
}

Dot Triangle::get_dot_two()
{
	return *dot_two;
}

void Triangle::set_dot_three(Dot* dotThree)
{
	dot_three = dotThree;
}

Dot Triangle::get_dot_three()
{
	return *dot_three;
}

double* Triangle::create_masSide()
{
	double mas[3];
	mas[0] = dot_one->distanceTo(*dot_two);
	mas[1] = dot_two->distanceTo(*dot_three);
	mas[2] = dot_three->distanceTo(*dot_one);
	return mas;
}

void Triangle::output_len_side()
{
	double* mas;
	mas = create_masSide();
	double side_A = mas[0];
	double side_B = mas[1];
	double side_C = mas[2];
	cout << "Длина стороны А: " << side_A << endl;
	cout << "Длина стороны B: " << side_B << endl;
	cout << "Длина стороны C: " << side_C << endl;
}

double Triangle::calc_perimetr()
{
	double* mas;
	mas = create_masSide();
	return mas[0] + mas[1] + mas[2];
}

double Triangle::calc_square()
{
	double* mas;
	mas = create_masSide();
	double square, pp;
	pp = this->calc_perimetr() / 2;
	square = sqrt(pp * (pp - mas[0]) * (pp - mas[1]) * (pp - mas[2]));
	return square;
}