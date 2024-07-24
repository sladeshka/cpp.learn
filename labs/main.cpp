#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <string>
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

int main()
{
	//lab0();
	//lab1_1();
	//lab1_2();
	//lab1_3();
	test1();
	//lab2_1();
	//lab2_2();
	//lab2_3();
	//lab2_4();
	test2();
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