#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <regex>
#include <math.h>
#include <vector>
#include <tuple>
#include "Student.h"
#include "Time.h"
#include "Triangle.h"
#include "IdCard.h"
#include "Dot.h"

using namespace std;
using Tuple = tuple<string, int, double>;
using NewTuple = tuple<string, double>;

void lab0();
void lab1_1();
void lab1_2();
void lab1_3();
void test1();
void lab2_1();
void lab2_2();
void lab2_3();
void lab2_4();
void test2();
void lab3_1();
void hello(string);
void lab3_2();
void lab3_3();
void lab3_4();
void test3();
void lab4_1();
void lab4_2();
void test4();
void lab5_1();
void lab5_2();
void lab5_3();
void lab5_4();
void lab5_5();
void test5();
void lab6_1();
void test6();
//void lab7_1();
void lab7_2();
void lab7_3();
void lab7_4();
void lab7_5();
void test7();
void lab8_1();
void lab8_2();
void lab8_3();
void lab8_4();
void lab8_5();
void test8();
void lab9_1();
void lab9_2();
void lab9_3();
void test9();
void lab10_1();
void test10();

int main()
{
	//lab0();
	//lab1_1();
	//lab1_2();
	//lab1_3();
	//test1();
	//lab2_1();
	//lab2_2();
	//lab2_3();
	//lab2_4();
	//test2();
	//lab3_1();
	//lab3_2();
	//lab3_3();
	//lab3_4();
	//test3();
	//lab4_1();
	//lab4_2();
	test4();
	//lab5_1();
	//lab5_2();
	//lab5_3();
	//lab5_4();
	//lab5_5();
	test5();
	//lab6_1();
	test6();
	//lab7_1();
	//lab7_2();
	//lab7_3();
	//lab7_4();
	//lab7_5();
	test7();
	//lab8_1();
	//lab8_2();
	//lab8_3();
	//lab8_4();
	//lab8_5();
	test8();
	//lab9_1();
	//lab9_2();
	//lab9_3();
	test9();
	//lab10_1();
	test10();
}

static void lab0()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	cout << "Hello World!\n";
}

static void lab1_1()
{
	string name;
	cout << "What is your name?\n";
	// cin >> name;
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}

static void lab1_2()
{
	cout.precision(3);
	system("chcp 1251");
	string name;
	double a, b;
	cout << "What is your name?\n";
	cout << "Enter a and b:\n";
	cin >> a;
	cin >> name;
	cin >> b;
	double x = a / b;
	//int x = a / b;
	cout << "\nx = " << x << endl;
	cout << "Hello, " << name << "!\n";
	cout << sizeof(a / b) << ends << sizeof(x) << endl;
}

static void lab1_3()
{
	double perimeter;
	double side;
	double halfPerimeter;
	double area;
	cout << "Enter the perimeter of an equilateral triangle:\n";
	cin >> perimeter;
	side = perimeter / 3.0;
	halfPerimeter = perimeter / 2.0;
	area = sqrt(halfPerimeter * (halfPerimeter - side) * (halfPerimeter - side) * (halfPerimeter - side));
	cout << "Side\tSquare\n";
	cout << "Value\tResult\n";
	cout << side << "\t" << fixed << setprecision(2) << area << endl;
}

struct Point {
	double x;
	double y;
};

double signedArea(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
}

double polygonArea(const Point points[], int n) {
	double area = 0.0;
	for (int i = 0; i < n - 2; i++) {
		area += signedArea(points[0], points[i + 1], points[i + 2]);
	}
	return abs(area);
}

static void test1()
{
	Point points[5];
	cout << "Enter the coordinates of the pentagon vertices:\n";
	for (int i = 0; i < 5; i++) {
		cout << "Vertex " << i + 1 << ": ";
		cin >> points[i].x >> points[i].y;
	}
	double area = polygonArea(points, 5);
	cout << "Pentagon area : " << area << endl;
}

static void lab2_1() {
	//task 1
	double x;
	cin >> x;
	double y;
	cin >> y;
	if (x * x + y * y < 9 && y > 0)
		cout << "inside" << endl;
	else if (x * x + y * y > 9 || y < 0)
		cout << "outside" << endl;
	else cout << "on the border" << endl;
	//task 2
	char op;
	cout << "Make your choice, assemble the car of your dreams: ";
	cin >> op;
	switch (op) {
	case 'V':
		cout << "The radio must play\n";
		//cout << "Round wheels\n";
		//cout << "Powerful engine\n";
		//break;
	case 'S':
		cout << "I want air conditioning\n";
		//cout << "The radio must play\n";
		//cout << "Round wheels\n";
		//cout << "Powerful engine\n";
		//break;
	default:
		cout << "Round wheels\n";
		cout << "Powerful engine\n";
	}
}

static void lab2_2() {
	//task 1
	double x, x1, x2, y;
	cout << "x1 = "; cin >> x1;
	cout << "x2 = "; cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);
	//task 2
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << "GCD = " << a << endl;
}

static void lab2_3() {
	//task 1
	srand(time(NULL));
	int a, b, c;
	int k = 0, n = 10;
	for (int i = 1; i <= n; i++) {
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		if (a * b != c)
		{
			k++;
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
	}
	cout << "Count error: " << k << endl;
}

static void lab2_4() {
	int s = 0, m, k;
	cout << "k = ";
	cin >> k;
	cout << "m = ";
	cin >> m;
	for (int i = 1; i <= 100; i++)
	{
		if ((i > k) && (i < m))
			continue;
		s += i;
	}
	cout << "s = " << s;
}

//task 1
bool isSuperPrime(int n) {
	int superPrime[51] = { 3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, 211,
		241, 277, 283, 331, 353, 367, 401, 431, 461, 509, 547, 563,
		587, 599, 617, 709, 739, 773, 797, 859, 877, 919, 967, 991,
		1031, 1063, 1087, 1153, 1171, 1201, 1217, 1297, 1409, 1433,
		1447, 1471 };
	for (int i = 0; i < 51; i++)
	{
		if (superPrime[i] == n) {
			return true;
		}
		superPrime[i] == n;
	}
	return false;
}
//task 2
bool checkSNILS(string snils) {
	if (snils.length() != 11) {
		return false;
	}
	for (int i = 0; i < 8; ++i) {
		if (snils[i] == snils[i + 1]) {
			if (i >= 1 && snils[i - 1] == snils[i]) {
				return false;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		sum += (snils[8 - i] - '0') * (i + 1);
	}
	int controlNumber = 0;
	if (sum < 100) {
		controlNumber = sum;
	}
	else if (sum == 100 || sum == 101) {
		controlNumber = 0;
	}
	else {
		controlNumber = sum % 101;
		if (controlNumber == 100) {
			controlNumber = 0;
		}
	}
	if (controlNumber != (snils[9] - '0') * 10 + (snils[10] - '0')) {
		return false;
	}

	return true;
}
//task 3
void change(int amount) {
	const int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000, 5000 };
	const int numCoins = sizeof(coins) / sizeof(coins[0]);

	vector<int> result;
	for (int i = numCoins - 1; i >= 0; --i) {
		while (amount >= coins[i]) {
			amount -= coins[i];
			result.push_back(coins[i]);
		}
	}
	cout << "Set of coins:\n";
	for (int coin : result) {
		cout << coin << "\n";
	}
}
//task 4
string getShooterLevel(int score) {
	if (score >= 80) return "Sniper";
	else if (score >= 50) return "Just a shooter";
	else return "Newbie";
}
int shot(int x, int y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}
static void test2() {
	//task 1
	int n;
	bool notTrue = true;
	while (notTrue)
	{
		cout << "Enter a number to check if it's super prime: ";
		cin >> n;
		if (isSuperPrime(n)) {
			notTrue = false;
			cout << "It's a super prime number\n";
		}
		else {
			cout << "It's not a super prime number\n";
		}
	}
	//task 2
	// example 52099009077
	notTrue = true;
	string snils;
	while (notTrue)
	{
		cout << "Enter number SNILS: ";
		cin >> snils;
		if (checkSNILS(snils)) {
			notTrue = false;
			cout << "SNILS number is correct\n";
		}
		else {
			cout << "Invalid SNILS number format\n";
		}
	}
	//task 3
	int amount;
	cout << "Enter amount: ";
	cin >> amount;
	change(amount);
	//task 4
	const int AMMO = 10;
	const int MAX_SCORE = 80;
	int score = 0;
	int attempts = 0;
	cout << "You have " << AMMO << " rounds\n";
	while (attempts <= AMMO && score <= MAX_SCORE)
	{
		int x, y;
		cout << "Enter shot coordinates: \nx: ";
		cin >> x;
		cout << "\ny: ";
		cin >> y;
		int shotResult = shot(x, y);
		switch (shotResult)
		{
		case 1:
			score += 10;
			cout << "Hitting the center!+ 10 points\n";
			break;
		case 2:
			score += 5;
			cout << "Hit the ring! +5 points\n";
			break;
		case 3:
			cout << "Missing the target\n";
			break;
		default:
			cout << "Missing the target\n";
			break;
		}
		attempts++;
	}
	cout << "For " << attempts << " shots you got " << score << " points. " << getShooterLevel(score) << endl;
}

string getHello(string name) {
	string str = name + ", " + "hello!\n";
	return str;
}

void lab3_1() {
	//task 1
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	hello(name);
	//task 2
	//string name;
	//cout << "What is your name?" << endl;
	//cin >> name;
	string hello = getHello(name);
	cout << hello;
}

void hello(string name) {
	cout << name << ", " << "hello!" << endl;
}

void hello(string name, int k)
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}

void lab3_2() {
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	int k;
	cout << "Input number:" << endl;
	cin >> k;
	hello(name, k);
}

long double firBinSearch(double a, int n)
{
	double L = 0;
	double R = a;
	while (R - L > 1e-10)
	{
		double M = (L + R) / 2;
		if (pow(M, n) < a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	return R;
}

void lab3_3() {
	cout.precision(7);
	double a;
	int n;
	cout << "Calculate the nth root of a using real binary search.\n";
	cout << "To do this, enter two numbers separated by a space\n";
	cout << "where the first a is real, greater than or equal to 1, does not exceed 1000, specified with an accuracy of 6 digits after the decimal point\n";
	cout << "where the second n is a natural number not exceeding 10\n";
	cin >> a >> n;
	cout << firBinSearch(a, n) << endl;
}

int up(int n)
{
	if (n == 1) return 1;
	else return (n + up(n - 1));
}

int up(int n1, int n2)
{
	if (n1 == 1) return 1;
	else return (n1 + up(n2 - 1));
}

int down(int n)
{
	if (n == 1) return 1;
	else return (n - down(n - 1));
}

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m % n);
}

void lab3_4() {
	//task 1
	int n, n1, n2;
	cout << "Enter number: ";
	cin >> n;
	cout << up(n) << endl;
	cout << down(n) << endl;
	cout << "Enter first number: ";
	cin >> n1;
	cout << "Enter second number: ";
	cin >> n2;
	cout << up(n1, n2) << endl;
	//task 2
	cout << "Greatest common divisor\n";
	cout << gcd(n1, n2) << endl;
}

bool checkSNILS(string snils, bool override) {
	snils = regex_replace(snils, regex("[ -]"), "");
	return checkSNILS(snils);
}

double cubicRoot(double x) {
	return pow(x, 1.0 / 3);
}

double cubicRoot(double x, bool iterative) {
	double result = x;
	double epsilon = 1e-9;
	while (true) {
		double nextResult = (2 * result + x / (result * result)) / 3;
		if (fabs(nextResult - result) < epsilon) {
			return nextResult;
		}
		result = nextResult;
	}
}

double triangleArea(double side) {
	return sqrt(3) * side * side / 4;
}

double triangleArea(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int sumSeries(int n) {
	if (n == 1) {
		return 5;
	}
	else {
		return 5 * n + sumSeries(n - 1);
	}
}

void decimalToBinary(int num) {
	if (num > 0) {
		decimalToBinary(num / 2);
		cout << num % 2;
	}
}

void test3() {
	//task 1
	// example 520-990-090 77
	bool notTrue = true;
	string snils;
	while (notTrue)
	{
		cout << "\nEnter number SNILS: ";
		getline(cin, snils);
		if (checkSNILS(snils, true)) {
			notTrue = false;
			cout << "SNILS number is correct\n";
		}
		else {
			cout << "Invalid SNILS number format\n";
		}
	}
	//task 2
	int n;
	cout << "Enter number: ";
	cin >> n;;
	cout << "Pow : " << cubicRoot(n) << endl;
	cout << "Iterative : " << cubicRoot(n, true) << endl;
	//task 3
	int choice;
	cout << "Select triangle type:\n";
	cout << "1. Equilateral triangle\n";
	cout << "2. Scalene triangle\n";
	cout << "Enter triangle type number: ";
	cin >> choice;

	if (choice == 1) {
		double side;
		cout << "Enter the side of an equilateral triangle: ";
		cin >> side;
		double area = triangleArea(side);
		cout << "Area of an equilateral triangle: " << area << endl;
	}
	else if (choice == 2) {
		double a, b, c;
		cout << "Enter the sides of an equilateral triangle: ";
		cin >> a >> b >> c;
		double area = triangleArea(a, b, c);
		cout << "Area of an equilateral triangle: " << area << endl;
	}
	else {
		cout << "Wrong choice of triangle type." << endl;
	}
	//task 4
	//int n;
	cout << "Enter n number: ";
	cin >> n;

	if (n > 0) {
		int result = sumSeries(n);
		cout << "Sum of series : " << result << endl;
	}
	else {
		cout << "The value of n must be greater than 0." << endl;
	}
	//task 5
	//int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	if (n > 0) {
		cout << "Binary representation: ";
		decimalToBinary(n);
		cout << endl;
	}
	else {
		cout << "The number entered must be positive." << endl;
	}
}

void fum_value(double k, double x, double y)
{
	x = x + k;
	y = y + k;
}

void fum_ptr(double k, double* x, double* y)
{
	*x = *x + k;
	*y = *y + k;
}

void fum_ref(double k, double& x, double& y)
{
	x = x + k;
	y = y + k;
}

void print(double x, double y)
{
	cout << "x = " << x << "; y = " << y << endl;
}

void lab4_1() {
	double k = 2.5;
	double xv = 10;
	double yv = 10;

	print(xv, yv);

	fum_value(k, xv, yv);
	print(xv, yv);

	fum_ptr(k, &xv, &yv);
	print(xv, yv);

	fum_ref(k, xv, yv);
	print(xv, yv);
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void lab4_2() {
	int x = 5, y = 10;
	cout << " x = " << x << " y = " << y << endl;
	swap(&x, &y);
	cout << " x = " << x << " y = " << y << endl;
	swap(x, y);
	cout << " x = " << x << " y = " << y << endl;
}

int QuadraticEquationCoefficients(double a, double b, double c, double& x1, double& x2) {
	double d;
	short flag;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		x1 = (-b - sqrt(d)) / (2 * a);
		x2 = (-b + sqrt(d)) / (2 * a);
		return flag = 1;
	}
	else if (d == 0)
	{
		x1 = -b / (2 * a);
		return flag = 0;
	}
	else
		return flag = -1;
}

bool enterNumber(int& a, int& b) {
	string strA, strB;
	bool flag = true;
	cout << "Enter number a = " << endl;
	cin >> strA;
	cout << "Enter number b = " << endl;
	cin >> strB;
	for (int i = 0; i < strA.length(); i++)
	{
		if (!isdigit(strA[i]))
			if (strA[i] == '-' && i == 0)
				continue;
			else
			{
				flag = false;
				break;
			}
	}
	for (int i = 0; i < strB.length(); i++)
	{
		if (!isdigit(strB[i]))
			if (strA[i] == '-' && i == 0)
				continue;
			else
			{
				flag = false;
				break;
			}
	}
	if (flag == true)
	{
		a = atoi(strA.c_str());
		b = atoi(strB.c_str());
	}
	return flag;
}

void test4() {
	//task 1
	double a, b, c, x1, x2;
	int d;
	cout << "Enter the coefficients of the quadratic equation(separated by spaces): ";
	cin >> a >> b >> c;
	d = QuadraticEquationCoefficients(a, b, c, x1, x2);
	switch (d)
	{
	case 1:
		cout << "Roots of the equation x1 = " << x1 << ", x2 = " << x2;
		break;
	case 0:
		cout << "The root of the equation is one x1 = x2 = " << x1;
		break;
	case -1:
		cout << "There are no roots of the equation";
		break;
	}
	//task 2
	int a2, b2;
	if (enterNumber(a2, b2) == false)
	{
		cerr << "error";
	}
	int s = a2 + b2;
	cout << s;
}



void lab5_1() {
	const int n = 10;
	int mas[n];
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}
	int s = 0;
	bool flagNeg = false, flagPos = false;
	int sumNeg = 0, sumPos = 0;
	int sumEven = 0, sumOdd = 0;
	int maxVal, maxIndex, minVal, minIndex;
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
		if (mas[i] < 0)
		{
			sumNeg += mas[i];
			flagNeg = true;
		}
		else
		{
			sumPos += mas[i];
			flagPos = true;
		}
		if (i % 2 == 0)
			sumEven += mas[i];
		else
			sumOdd += mas[i];
		if (i == 0)
		{
			maxVal = mas[i];
			maxIndex = i;
			minVal = mas[i];
			minIndex = i;
		}
		else
		{
			if (mas[i] > maxVal)
			{
				maxVal = mas[i];
				maxIndex = i;
			}
			if (mas[i] < minVal)
			{
				minVal = mas[i];
				minIndex = i;
			}
		}
	}
	cout << "Sum of array element values: " << s << endl;
	double mid;
	mid = double(s) / n;
	cout << "Average value of array elements: " << mid << endl;
	if (flagNeg == true)
		cout << "Sum of negative array elements: " << sumNeg << endl;
	else
		cout << "There are no negative elements in the array!" << endl;
	if (flagPos == true)
		cout << "Sum of positive array elements: " << sumPos << endl;
	else
		cout << "There are no positive elements in the array!" << endl;
	cout << "Sum of even array elements: " << sumEven << endl;
	cout << "Sum of odd array elements: " << sumEven << endl;
	cout << "Maximum array element value: " << maxVal << ", its index: " << maxIndex << endl;
	cout << "Minimum array element value: " << minVal << ", its index: " << minIndex << endl;
	int sumEntMinMax = 1;
	for (int i = min(maxIndex, minIndex); i < max(maxIndex, minIndex) - 1; i++)
	{
		if (max(maxIndex, minIndex) - min(maxIndex, minIndex) > 1)
		{
			sumEntMinMax *= mas[i + 1];
		}
		else
			sumEntMinMax = 1;
	}
	if (sumEntMinMax == 1)
		cout << "There are no elements between the minimum and maximum values" << endl;
	else
		cout << "Product of elements between minimum and maximum value = " << sumEntMinMax << endl;
}

void lab5_2() {
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	for (int i : a)
		cout << i << '\t';
}

void show_array(const int Arr[], const int N)
{
	for (int i = 0; i < N; i++)
		cout << Arr[i] << "  ";
	cout << "\n";
}

bool from_min(const int a, const int b)
{
	return a > b;
}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
		}
	}
}

void lab5_3() {
	bool (*from_f[2])(int, int) = { from_min,from_max };
	const int N = 10;
	int my_choose = 0;
	int A[N] = { 9,8,7,6,1,2,3,5,4,9 };
	cout << "1. Sort Ascending\n";
	cout << "2. Sort descending\n";
	cin >> my_choose;
	cout << "\rUnknown operation ";
	show_array(A, N);
	bubble_sort(A, N, (from_f[my_choose - 1]));
	show_array(A, N);
}

void lab5_4() {
	int n;
	cout << "Enter the number of array elements: ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}
	int s = 0;
	bool flagNeg = false, flagPos = false;
	int sumNeg = 0, sumPos = 0;
	int sumEven = 0, sumOdd = 0;
	int maxVal, maxIndex, minVal, minIndex;
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
		if (mas[i] < 0)
		{
			sumNeg += mas[i];
			flagNeg = true;
		}
		else
		{
			sumPos += mas[i];
			flagPos = true;
		}
		if (i % 2 == 0)
			sumEven += mas[i];
		else
			sumOdd += mas[i];
		if (i == 0)
		{
			maxVal = mas[i];
			maxIndex = i;
			minVal = mas[i];
			minIndex = i;
		}
		else
		{
			if (mas[i] > maxVal)
			{
				maxVal = mas[i];
				maxIndex = i;
			}
			if (mas[i] < minVal)
			{
				minVal = mas[i];
				minIndex = i;
			}
		}
	}
	cout << "Sum of array element values: " << s << endl;
	double mid;
	mid = double(s) / n;
	cout << "Average value of array elements: " << mid << endl;
	if (flagNeg == true)
		cout << "Sum of negative array elements: " << sumNeg << endl;
	else
		cout << "There are no negative elements in the array!" << endl;
	if (flagPos == true)
		cout << "Sum of positive array elements: " << sumPos << endl;
	else
		cout << "There are no positive elements in the array!" << endl;
	cout << "Sum of even array elements: " << sumEven << endl;
	cout << "Sum of odd array elements: " << sumEven << endl;
	cout << "Maximum array element value: " << maxVal << ", its index: " << maxIndex << endl;
	cout << "Minimum array element value: " << minVal << ", its index: " << minIndex << endl;
	int sumEntMinMax = 1;
	for (int i = min(maxIndex, minIndex); i < max(maxIndex, minIndex) - 1; i++)
	{
		if (max(maxIndex, minIndex) - min(maxIndex, minIndex) > 1)
		{
			sumEntMinMax *= mas[i + 1];
		}
		else
			sumEntMinMax = 1;
	}
	if (sumEntMinMax == 1)
		cout << "There are no elements between the minimum and maximum values" << endl;
	else
		cout << "Product of elements between minimum and maximum value = " << sumEntMinMax << endl;
}

void lab5_5() {
	int a, b, c;
	int k = 0;
	const int n = 10;
	int mas[n];
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		mas[i] = c;
		if (a * b != c)
		{
			v2.push_back(c);
			k++;
		}
		else
		{
			v1.push_back(c);
		}
	}
	cout << "\nAll: ";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << ends;
	}
	cout << "\nGood: ";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ends;
	}
	cout << "\nBad: ";
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << ends;
	}
}

void arrayOperations(const int n, int mas[])
{
	int s = 0;
	bool flagNeg = false, flagPos = false;
	int sumNeg = 0, sumPos = 0;
	int sumEven = 0, sumOdd = 0;
	int maxVal, maxIndex, minVal, minIndex;
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
		if (mas[i] < 0)
		{
			sumNeg += mas[i];
			flagNeg = true;
		}
		else
		{
			sumPos += mas[i];
			flagPos = true;
		}
		if (i % 2 == 0)
			sumEven += mas[i];
		else
			sumOdd += mas[i];
		if (i == 0)
		{
			maxVal = mas[i];
			maxIndex = i;
			minVal = mas[i];
			minIndex = i;
		}
		else
		{
			if (mas[i] > maxVal)
			{
				maxVal = mas[i];
				maxIndex = i;
			}
			if (mas[i] < minVal)
			{
				minVal = mas[i];
				minIndex = i;
			}
		}
	}
	cout << "Sum of array element values: " << s << endl;
	double mid;
	mid = double(s) / n;
	cout << "Average value of array elements: " << mid << endl;
	if (flagNeg == true)
		cout << "Sum of negative array elements: " << sumNeg << endl;
	else
		cout << "There are no negative elements in the array!" << endl;
	if (flagPos == true)
		cout << "Sum of positive array elements: " << sumPos << endl;
	else
		cout << "There are no positive elements in the array!" << endl;
	cout << "Sum of even array elements: " << sumEven << endl;
	cout << "Sum of odd array elements: " << sumEven << endl;
	cout << "Maximum array element value: " << maxVal << ", its index: " << maxIndex << endl;
	cout << "Minimum array element value: " << minVal << ", its index: " << minIndex << endl;
	int sumEntMinMax = 1;
	for (int i = min(maxIndex, minIndex); i < max(maxIndex, minIndex) - 1; i++)
	{
		if (max(maxIndex, minIndex) - min(maxIndex, minIndex) > 1)
		{
			sumEntMinMax *= mas[i + 1];
		}
		else
			sumEntMinMax = 1;
	}
	if (sumEntMinMax == 1)
		cout << "There are no elements between the minimum and maximum values" << endl;
	else
		cout << "Product of elements between minimum and maximum value = " << sumEntMinMax << endl;
}

void arrayReplace(const int N, int a[])
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	for (int i = 0; i < N; i++)
		cout << a[i] << '\t';
}

int* max_vect(int kc, int a[], int b[])
{
	int* arrayMax = new int[kc];
	for (int i = 0; i < kc; i++)
	{
		if (a[i] >= b[i])
			arrayMax[i] = a[i];
		else
			arrayMax[i] = b[i];
	}
	return arrayMax;
}

void searhTrans(int mas[], int value, int n)
{
	int index;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] == value)
		{
			index = i;
			if (index == 0)
				break;
			else
				swap(mas[i], mas[i - 1]);
		}
	}
}

void funcResult(string inputStr, int& result, bool& flag)
{
	vector<string> argv;
	string cnt;
	for (int i = 0; i <= inputStr.length(); ++i)
	{
		if (inputStr[i] == ' ' || i == inputStr.length())
		{
			argv.push_back(cnt);
			cnt = "";
		}
		else
			cnt += inputStr[i];
	}
	for (int i = 0; i < argv.size(); i++)
	{
		cout << argv[i] << endl;
	}
	if (argv.size() != 4 || strncmp(argv[0].c_str(), "nameProg", 8) != 0)
	{
		cout << strncmp(argv[0].c_str(), "nameProg", 8);
		flag = false;
	}
	else
	{
		if (strncmp(argv[1].c_str(), "-a", 2) == 0)
			result = atoi(argv[2].c_str()) + atoi(argv[3].c_str());
		else if (strncmp(argv[1].c_str(), "-m", 2) == 0)
			result = atoi(argv[2].c_str()) * atoi(argv[3].c_str());
		else
			flag = false;
	}
}

void test5() {
	//task 1
	const int n = 10;
	int mas[n];
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}
	const int size = 10;
	int a[size] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	arrayOperations(n, mas);
	arrayReplace(size, a);
	//task 2
	int a2[] = { 1,2,3,4,5,6,7,2 };
	int b2[] = { 7,6,5,4,3,2,1,3 };

	int kc = sizeof(a2) / sizeof(a2[0]);
	int* c2;
	c2 = max_vect(kc, a2, b2);

	for (int i = 0; i < kc; i++)
		cout << c2[i] << " ";
	cout << endl;
	delete[]c2;
	//task 3
	int mas3[] = { 1, 2, 3, 4, 7, 5, 9, 5, 6, 7, 8 };
	int c3, value3 = 4;
	int n3 = sizeof(mas3) / sizeof(mas3[0]);
	cout << "Primordial Array" << endl;
	for (int i : mas3)
		cout << i << '\t';
	for (int i = 0; i < 5; i++)
	{
		searhTrans(mas3, value3, n3);
		cout << "\nFinal array" << endl;
		for (int i : mas3)
			cout << i << '\t';
	}
	//task 4
	string inputStr;
	vector<string> argv;
	int argc = 0, result = 0;
	bool flag = true;
	getline(cin, inputStr);
	string cnt;
	for (int i = 0; i < inputStr.length(); i++)
	{
		if (inputStr[i] == ' ' || i == inputStr.length() - 1)
		{
			argv.push_back(cnt);
			argc++;
			cnt = "";
		}
		else
			cnt += inputStr[i];
	}
	funcResult(inputStr, result, flag);
	if (flag == true)
		cout << "Result: " << result;
	else
		cout << "ERROR!";
}

void lab6_1() {
	double sum = 0;
	int const n = 100;
	double nums[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = (rand() % 100);
	}
	ofstream out("test", ios::out | ios::binary);
	if (!out) {
		cout << "The file cannot be opened\n";
	}
	out.write((char*)nums, sizeof(nums));
	out.close();
	ifstream in("test", ios::in | ios::binary);
	if (!in) {
		cout << "The file cannot be opened";
	}
	in.read((char*)&nums, sizeof(nums));
	int k = sizeof(nums) / sizeof(double);
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
		cout << nums[i] << ' ';
	}
	cout << "\nsum = " << sum << endl;
	in.close();
}

void test6_1() {
	ofstream os("Text.txt");
	if (!os)
	{
		cout << "The file cannot be opened \n";
	}
	string text;
	cout << "Test" << endl;
	do
	{
		getline(cin, text);
		if (*text.c_str() == 'f')
			break;
		else
			os << text << endl;
	} while (true);
	os.close();
}

void writeFile(string text)
{
	ofstream f("Text.txt", ios::app);
	f << text << '\n';
	f.close();
}

void test6_2() {
	string text;
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		text.append(to_string(a[i]));
		text.append(" ");
	}
	writeFile("Source array: " + text);
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	text = "";
	for (int i : a)
	{
		text.append(to_string(i));
		text.append(" ");
	}
	writeFile("Sorted array: " + text);
}

void test6() {
	//task 1
	test6_1();
	//task 2
	test6_2();
}

struct Distance {
	int feet;
	double inches;

	void ShowDist()
	{
		cout << feet << "\'-" << inches << "\"\n";
	}
};

/*Distance AddDist(Distance d1, Distance d2)
{
	Distance d;
	d.feet = d1.feet + d2.feet;
	d.inches = d1.inches + d2.inches;
	if (d.inches >= 12.0)
	{
		d.inches -= 12.0;
		d.feet++;
	}
	return d;
}*/

Distance InputDist() {
	Distance d;
	cout << "\nEnter the number of numbers : ";
	cin >> d.feet;
	cout << "Enter number of inches: ";
	cin >> d.inches;
	return d;
}

/*void lab7_1() {
	Distance d1 = InputDist();
	Distance d2 = { 1, 6.25 };
	Distance d3 = AddDist(d1, d2);
	d1.ShowDist();
	d2.ShowDist();
	d3.ShowDist();
}*/

Distance AddDist(const Distance& d1, const Distance& d2) {
	Distance d;
	d.feet = d1.feet + d2.feet;
	d.inches = d1.inches + d2.inches;
	if (d.inches >= 12.0)
	{
		d.inches -= 12.0;
		d.feet++;
	}
	return d;
}

void lab7_2() {
	Distance d1 = InputDist();
	Distance d2 = { 1, 6.25 };
	Distance d3 = AddDist(d1, d2);
	d1.ShowDist();
	d2.ShowDist();
	d3.ShowDist();
}

void ShowDist(Distance d)
{
	cout << d.feet << "\'-" << d.inches << "\"\n";
}

Distance SummaMasDist(Distance masDist[], int n)
{
	Distance d;
	d.feet = 0;
	d.inches = 0;
	for (int i = 0; i < n; i++)
	{
		d.feet += masDist[i].feet;
		d.inches += masDist[i].inches;
		while (d.inches >= 12.0)
		{
			d.inches -= 12.0;
			d.feet++;
		}
	}
	return d;
}


void lab7_3() {
	int n;
	Distance d;
	cout << "\nEnter the number of numbers : ";
	cin >> n;
	Distance* masDist = new Distance[n];
	for (int i = 0; i < n; i++)
	{
		masDist[i] = InputDist();
	}
	for (int i = 0; i < n; i++)
	{
		ShowDist(masDist[i]);
	}
	d = SummaMasDist(masDist, n);
	delete[] masDist;
	ShowDist(d);
}

void printTupleOfThree(tuple<string, int, double> t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
}

void lab7_4() {
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	printTupleOfThree(t0);
}


void printTupleOfThree(NewTuple t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ")" << endl;
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

Tuple mixtup(Tuple t)
{
	return make_tuple(get<0>(t).append("$"), get<1>(t) + 5, get<2>(t) / 3);
}

NewTuple tupNew(Tuple t)
{
	return make_tuple(get<0>(t).append(to_string(get<1>(t))), get<2>(t) * 1.12);
}

void lab7_5() {
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	auto t1 = funtup(v1[1], v2[1], v3[1]);
	auto t2 = mixtup(t0);
	auto t3 = tupNew(t0);
	printTupleOfThree(t0);
	printTupleOfThree(t1);
	printTupleOfThree(t2);
	printTupleOfThree(t3);
}

/*struct Time
{
	int hours;
	int minutes;
	int seconds;

	int ShowTime()
	{
		return hours * 3600 + minutes * 60 + seconds;
	}

	Time AddTime(Time t1)
	{
		Time t;
		t.hours = 0;
		t.minutes = 0;
		t.seconds = 0;
		if (seconds + t1.seconds > 59)
		{
			t.seconds = seconds + t1.seconds - 60;
			t.minutes++;
		}
		else
			t.seconds = seconds + t1.seconds;
		if (t.minutes + minutes + t1.minutes > 59)
		{
			t.minutes = t.minutes + minutes + t1.minutes - 60;
			t.hours++;
		}
		else
			t.minutes += minutes + t1.minutes;
		t.hours += hours + t1.hours;
		return t;
	}

	Time SubTime(Time t1)
	{
		Time t;
		t.hours = 0;
		t.minutes = 0;
		t.seconds = 0;
		if (seconds - t1.seconds < 0)
		{
			t.seconds = 60 + seconds - t1.seconds;
			t.minutes--;
		}
		else
			t.seconds = seconds - t1.seconds;
		if (t.minutes + minutes - t1.minutes < 0)
		{
			t.minutes = 60 + t.minutes + minutes - t1.minutes;
			t.hours--;
		}
		else
			t.minutes += minutes - t1.minutes;
		t.hours += hours - t1.hours;
		return t;
	}
};
*/

Time InputTime(bool& flag)
{
	Time t;
	cout << "Enter time: ";
	cin >> t.hours;
	cin >> t.minutes;
	cin >> t.seconds;
	if (t.hours < 0)
		flag = false;
	else if (t.minutes > 59 || t.minutes < 0 || t.seconds > 59 || t.seconds < 0)
		flag = false;
	return t;
}

void test7_1() {
	bool flag = true;
	Time t1 = InputTime(flag);
	Time t2 = InputTime(flag);
	string text = "Time in seconds: ";
	if (flag != true)
	{
		cout << "ERROR!";
	}
	else
	{
		int output = t1.getTime();
		cout << text << output << endl;
		output = t2.getTime();
		cout << text << output << endl;
		Time t3 = t1.AddTime(t2);
		output = t3.getTime();
		cout << text << output << endl;
		Time t4 = t1.SubTime(t2);
		output = t4.getTime();
		cout << text << output << endl;
	}
}

struct QuadEquation
{
	double root1;
	double root2;
};

QuadEquation SolvEquation(bool& flag)
{
	QuadEquation equat;
	double a, b, c;
	double d;
	cout << "Enter the coefficients of the quadratic equation(separated by spaces) : ";
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		equat.root1 = (-b - sqrt(d)) / (2 * a);
		equat.root2 = (-b + sqrt(d)) / (2 * a);
	}
	else if (d == 0)
	{
		equat.root1 = -b / (2 * a);
		equat.root2 = equat.root1;
	}
	else
		flag = false;
	return equat;
}


void test7_2() {
	bool flag = true;
	QuadEquation equat = SolvEquation(flag);
	if (flag != true)
	{
		cout << "There are no roots";
	}
	else
	{
		cout << "Root No. 1 of the equation: " << equat.root1 << endl;
		cout << "Root No. 2 of the equation: " << equat.root2 << endl;
	}
}

using Tuple2 = tuple<double, double, short>;

void printTupleOfThree(Tuple2 t, bool override)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}


Tuple2 SolvEquation()
{
	Tuple2 quadEqua;
	double a, b, c;
	double d;
	cout << "Enter the coefficients of the quadratic equation (separated by spaces): ";
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		return make_tuple((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a), 1);
	}
	else if (d == 0)
	{
		return make_tuple(-b / (2 * a), 0, 0);
	}
	else
		return make_tuple(0, 0, -1);
}

void test7_3() {
	Tuple2 quadEqua;
	quadEqua = SolvEquation();
	printTupleOfThree(quadEqua, true);
}

void test7() {
	test7_1();
	test7_2();
	test7_3();
}

/*class Student
{
public:
	void set_name(string student_name)
	{
		name = student_name;
	}

	string get_name()
	{
		return name;
	}

	void set_last_name(string student_last_name)
	{
		last_name = student_last_name;
	}

	string get_last_name()
	{
		return last_name;
	}

	void set_scores(int student_scores[])
	{
		for (int i = 0; i < 5; ++i) {
			scores[i] = student_scores[i];
		}
	}

	void set_average_score(double ball)
	{
		average_score = ball;
	}

	double get_average_score()
	{
		return average_score;
	}

private:
	int scores[5];
	double average_score;
	string name;
	string last_name;
};*/

void lab8_1() {
	Student student01;
	string name, last_name;
	int scores[5];
	cout << "Name: ";
	getline(cin, name);
	int sum = 0;

	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}

	student01.set_name(name);
	student01.set_last_name(last_name);
	student01.set_scores(scores);
	double average_score = sum / 5.0;
	student01.set_average_score(average_score);
	cout << "Average ball for " << student01.get_name() << " "
		<< student01.get_last_name() << " is "
		<< student01.get_average_score() << endl;
}


void lab8_2() {
	lab8_1();
}

void lab8_3() {
	Student* student01 = new Student;
	string name, last_name;
	cout << "Name: ";
	getline(std::cin, name);
	cout << "Last name: ";
	getline(std::cin, last_name);
	int scores[5];
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}
	student01->set_name(name);
	student01->set_last_name(last_name);
	student01->set_scores(scores);
	float average_score = sum / 5.0;
	student01->set_average_score(average_score);
	cout << "Average ball for " << student01->get_name() << " "
		<< student01->get_last_name() << " is "
		<< student01->get_average_score() << endl;
	delete student01;
}

void lab8_4() {
	string name, last_name;
	cout << "Name: ";
	getline(cin, name);
	cout << "Last name: ";
	getline(cin, last_name);
	Student* student02 = new Student(name, last_name);
	int scores[5];
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}
	student02->set_scores(scores);
	double average_score = sum / 5.0;
	student02->set_average_score(average_score);
	cout << "Average ball for " << student02->get_name() << " "
		<< student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;
	delete student02;
}

void lab8_5() {
	lab8_4();
}

void test8() {
	const Time* time1 = new Time(2, 70, 40);
	const Time* time2 = new Time(-5, 20, 30);
	time1->ShowTime();
	time2->ShowTime();
	Time time3;
	time3.AddTime(time1, time2);
	delete time1;
	delete time2;
	time3.ShowTime();
}

class DivideByZeroError
{
public:
	DivideByZeroError() : message("Division by zero") { }
	void printMessage() const { cout << message << endl; }
private:
	string message;
};

float quotient(int numl, int num2)
{
	if (num2 == 0)
		throw DivideByZeroError();
	return  (float)numl / num2;
}

void lab9_1() {
	cout << "Enter two integers to calculate their quotient:\n";
	int number1, number2;
	cin >> number1;
	cin >> number2;
	try
	{
		float result = quotient(number1, number2);
		cout << "The quotient is equal to " << result << endl;
	}
	catch (DivideByZeroError& error)
	{
		cout << "ERROR: ";
		error.printMessage();
	}
}

void lab9_2() {
	cout << "Enter an integer to calculate their quotient : \n";
	int number1;
	cin >> number1;
	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "The quotient is equal to " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "ERROR: ";
			error.printMessage();
		}
	}
}
void lab9_3() {
	Student student01;
	string name;
	string last_name;
	int scores[5];
	cout << "Name: ";
	getline(cin, name);
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}
	student01.set_name(name);
	student01.set_last_name(last_name);
	try
	{
		student01.set_scores(scores);
	}
	catch (Student::ExScore& ex)
	{
		cout << "\nInitialization error " << ex.origin;
		cout << "\nEntered rating value " << ex.iValue <<
			" is invalid\n";
	}
	double average_score = sum / 5.0;
	student01.set_average_score(average_score);

	cout << "Average ball for " << student01.get_name() << " "
		<< student01.get_last_name() << " is "
		<< student01.get_average_score() << endl;
}

void test9_1() {
	try
	{
		Triangle* triangle1 = new Triangle(3, 4, 7);
		double sq = triangle1->calc_square(triangle1);
		delete triangle1;
		cout << "The area of the triangle is " << sq << endl;
	}
	catch (Triangle::TriangleError& error)
	{
		cout << "ERROR: ";
		error.printMessage();
	}
}

void test9_2() {
	try
	{
		const Time* time1 = new Time(2, 2, 40);
		const Time* time2 = new Time(-5, 20, 30);
		time1->ShowTime();
		time2->ShowTime();
		Time time3;
		time3.AddTime(time1, new Time(2, 2, -40));
		delete time1;
		delete time2;
		time3.ShowTime();
	}
	catch (Time::TimeError& error)
	{
		cout << "ERROR: ";
		error.printMessage();
	}
}

void test9() {
	test9_1();
	test9_2();
}

void lab10_1() {
	IdCard* idc = new IdCard(123, "Base");
	string name = "Ivan";
	string last_name = "Ivanov";
	Student* student02 = new Student(name, last_name, idc);
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;
	int num; string cat;
	cout << "IdCard: " << endl;
	cin >> num;
	cout << "Category: " << endl;
	cin >> cat;
	idc->setNumber(num);
	idc->setCategory(cat);
	student02->setIdCard(idc);
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;
}

void test10_1() {
	Dot* dot1 = new Dot();
	Dot* dot2 = new Dot(0, 3);
	Dot* dot3 = new Dot(4, 3);
	Triangle* triangle = new Triangle(dot1, dot2, dot3);
	triangle->output_len_side();
	cout << "The perimeter of the triangle is: " << triangle->calc_perimetr() << endl;
	cout << "The area of the triangle is: " << triangle->calc_square() << endl;
}

void test10_2() {
	Triangle* triangle = new Triangle();
	triangle->output_len_side();
	cout << "The perimeter of the triangle is: " << triangle->calc_perimetr() << endl;
	cout << "The area of the triangle is: " << triangle->calc_square() << endl;
}


void test10() {
	test10_1();
	test10_2();
}