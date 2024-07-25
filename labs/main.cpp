#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <regex>
#include <math.h>
#include <vector>

using namespace std;

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
	test3();
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