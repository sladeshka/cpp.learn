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
#include "Teacher.h"
#include "Time.h"
#include "Triangle.h"
#include "IdCard.h"
#include "Dot.h"
#include "Distance.h"
#include "Point.h"
#include "Item.h"
#include "Paperbook.h"
#include "AudioBook.h"
#include "Group.h"
#include "A.h"
#include "Stack.h"
#include <map>

using namespace std;

void lab11_1();
void lab11_2();
void lab11_3();
void lab11_4();
void test11();
void lab12();
void lab13_1();
void test13();
void lab14_1();
void lab14_2();
void lab14_3();
void lab14_4();
void test14();
void lab15_1();
void lab15_2();
void test15();
void demo1();
void demo2();
void demo3();
void demo4();

int main()
{
	//lab11_1();
	//lab11_2();
	//lab11_3();
	//lab11_4();
	//test11();
	//lab12();
	//lab13_1();
	//test13();
	//lab14_1();
	//lab14_2();
	//lab14_3();
	//lab14_4();
	//test14();
	//lab15_1();
	//lab15_2();
	//test15();
	demo1();
	demo2();
	demo3();
	demo4();
}

void lab11_1() {
	Distance dist1, dist2, dist3, dist4;
	dist1.getdist();
	dist2.getdist();
	dist1 - dist2;
	dist1 + dist2 + dist3;
	cout << "\ndist1 = " << dist1;
	cout << "\ndist2 = " << dist2;
	cout << "\ndist3 = " << dist3;
	cout << "\ndist4 = " << dist4;
}

void lab11_2() {
	Distance dist2;
	Distance dist1 = 2.35F;
	float mtrs;
	mtrs = static_cast<float>(dist1);
	cout << "mtrs = " << mtrs;
	dist2.getdist();
	mtrs = dist2;
	cout << "\ndist1 = " << dist1;
	cout << "\nmtrs = " << mtrs;
}

void lab11_3() {
	Distance dist1;
	dist1.getdist();
	Distance dist2 = +2.0;
	Distance dist3 = 2.0 + dist1;
	cout << "\ndist1 = " << dist1;
	cout << "\ndist2 = " << dist2;
	cout << "\ndist3 = " << dist2;
}

struct StudentGrade
{
	string name;
	char grade;
	StudentGrade() {}
	StudentGrade(string name, char grade)
	{
		this->name = name;
		this->grade = grade;
	}
};

class GradeMap
{
private:
	vector<StudentGrade> m_map;
public:
	GradeMap()
	{ }
	char& operator[](const string& name)
	{
		for (auto& ref : m_map)
		{
			if (ref.name == name)
				return ref.grade;
		}
		StudentGrade temp{ name, ' ' };
		m_map.push_back(temp);
		return m_map.back().grade;
	}
};

void lab11_4() {
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	cout << "John has a grade of " << grades["John"] << endl;
	cout << "Martin has a grade of " << grades["Martin"] << endl;

	cout << "New name and grade?" << endl;
	string name;
	char grade;
	cin >> name >> grade;
	grades[name] = grade;
	cout << name << " has a grade of " << grades[name] << endl;
}

void test11_1() {
	Time time1(2, 45, 50);
	Time time2(2, 46, 51);
	time1.ShowTime();
	time2.ShowTime();
	Time time3, time4, time5;
	time3 = time1 + time2;
	time3.ShowTime();
	time4 = time1 - time2;
	time4.ShowTime();
	time5 = Time(2, 45, 50) + 2.5;
	time5.ShowTime();
	time5 = Time(2, 45, 50) + 2.0;
	time5.ShowTime();
	if (time5 > time1)
		time5.ShowTime();
}

void test11_2() {
	vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	sort(v.begin(), v.end());
	for (auto& point : v)
		cout << point << '\n';
}

void test11() {
	test11_1();
	test11_2();
}


void lab12() {
	vector<int> scores;
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	Student* stud = new Student("Petrov", "Ivan", "Alexeyevich", scores);
	cout << stud->get_full_name() << endl;
	cout << "Average score : " << stud->get_average_score() << endl;
	unsigned int teacher_work_time = 40;
	Teacher* tch = new Teacher("Sergeev", "Dmitriy", "Sergeevich", teacher_work_time);
	cout << tch->get_full_name() << endl;
	cout << "Number of hours : " << tch->get_work_time() << endl;
}

void lab13_1() {
	Item* pubarr[100];
	int n = 0;
	char choice;
	do
	{
		cout << "\nEnter data for a book or audio file(b / a) ? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new Paperbook;
		else
			pubarr[n] = new AudioBook;
		pubarr[n++]->getdata();
		cout << "Continue((y/n) ? ";
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++)
		pubarr[j]->putdata();
	cout << endl;
}

void test13() {
	vector<int> scores;
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	Student* stud = new Student("Petrov", "Ivan", "Alexeyevich", scores);
	cout << stud->get_full_name() << endl;
	cout << "Average score : " << stud->get_average_score() << endl;
	unsigned int teacher_work_time = 40;
	Teacher* tch = new Teacher("Sergeev", "Dmitriy", "Sergeevich", teacher_work_time);
	cout << tch->get_full_name() << endl;
	cout << "Number of hours: " << tch->get_work_time() << endl;
	Human* hum = new Human("Test", "Test", "Test");
	Teacher tch1 = Teacher("Test", "Test", "Test", 50);
	hum = &tch1;
	cout << hum->get_work_time() << endl;
	Human hum1 = Human("Test", "Test", "Test");
	Teacher tch2 = Teacher("Test", "Test", "Test", 100);
	hum1 = tch2;
	cout << hum1.get_work_time() << endl;
	Human& hum2{ tch2 };
	cout << hum2.get_work_time() << endl;
}

template<class T> void sorting(T arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		T x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}

template<class T> void printAr(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << "." << endl;
		else
			cout << arr[i] << "; ";
	}
}

void lab14_1() {
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, word";
	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
	//sorting(arr, k1);
	//for (int i = 0; i < k1; i++) cout << arr[i] << ";";
	//cout << endl;
	//sorting(arrd, k2);
	//for (int i = 0; i < k2; i++) cout << arrd[i] << ";";
	//cout << endl;
	//sorting(arrc, k3);
	//for (int i = 0; i < k3; i++) cout << arrc[i] << ";";
	//cout << endl;
	sorting(arr, k1);
	printAr(arr, k1);
	sorting(arrd, k2);
	printAr(arrd, k2);
	sorting(arrc, k3);
	printAr(arrc, k3);
}

template<class Tuple> void printTupleOfThree(Tuple t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
}

void lab14_2() {
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t3 = make_tuple(v1[0], v1[1], v2[2]);
	printTupleOfThree(t3);
}

template<class Tuple, size_t N> struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);
		cout << ", " << get<N - 1>(t);
	}
};

template<class Tuple> struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t)
	{
		cout << get<0>(t);
	}
};

template<class... Args> void printTuple(const tuple<Args...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << ")" << endl;
}

void lab14_3() {
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t1 = make_tuple(v1[0], v1[1], v3[0]);
	auto t2 = make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);
	printTuple(t1);
	printTuple(t2);
}

template<class T, class T1> class testArray
{
public:
	testArray(int size);
	T1 sum();
	T average_value();
	void show_array();
	int add_value(T);
private:
	T* data;
	int size;
	int index;
};

template<class T, class T1> T testArray<T, T1>::average_value()
{
	T1 sum = 0;
	for (int i = 0; i < index; i++) sum += data[i];
	return (sum / index);
}

template<class T, class T1> testArray<T, T1>::testArray(int size)
{
	data = new T[size];
	if (data == NULL)
	{
		cerr << "Error memory ---- exit program" << endl;
		exit(1);
	}
	testArray::size = size;
	testArray::index = 0;
}

template<class T, class T1> T1 testArray<T, T1>::sum()
{
	T1 sum = 0;
	for (int i = 0; i < index; i++) sum += data[i];
	return(sum);
}

template<class T, class T1> void testArray<T, T1>::show_array()
{
	for (int i = 0; i < index; i++) cout << data[i] << ' ';
	cout << endl;
}

template<class T, class T1> int testArray<T, T1>::add_value(T value)
{
	if (index == size)
		return(-1);
	else
	{
		data[index] = value;
		index++;
		return(0);
	}
}

void lab14_4() {
	testArray<int, long> numbers(100);
	testArray<float, float> values(200);
	int i;
	for (i = 0; i < 50; i++) numbers.add_value(i);
	numbers.show_array();
	cout << "Sum =  " << numbers.sum() << endl;
	cout << "Average =  " << numbers.average_value() << endl;

	for (i = 0; i < 100; i++) values.add_value(i * 100);
	values.show_array();
	cout << "Sum = " << values.sum() << endl;
	cout << "Average =  " << values.average_value() << endl;
}

template<class T> double calc_average(T arr[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

void test14_1() {
	int arr1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	cout << calc_average(arr1, size1) << endl;
	long arr2[] = { 10L, 20L, 30L, 40L, 50L };
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << calc_average(arr2, size2) << endl;
	double arr3[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	cout << calc_average(arr3, size3) << endl;
	char arr4[] = "Hello, word";
	int size4 = sizeof(arr4) / sizeof(arr4[0]);
	cout << calc_average(arr4, size4) << endl;
}

template<class T> void Print(T str, string razd)
{
	for (auto item : str)
	{
		if (item == *(str.end() - 1))
			cout << item << "\n";
		else
			cout << item << razd;
	}
}

void test14_2() {
	vector<int> data = { 1, 2, 3 };
	Print(data, ", ");
}

void test14() {
	test14_1();
	test14_2();
}

void lab15_1() {
	string name;
	string last_name;
	cout << "Name: ";
	getline(cin, name);
	cout << "Last name: ";
	getline(cin, last_name);
	IdCard* idc1 = new IdCard(1, "Test1");
	IdCard* idc2 = new IdCard(2, "Test2");
	Student student02(name, last_name, idc1);
	Student student03("Test1", "Test1", idc2);
	Student student04("Test2", "Test2", idc1);
	Student student05("Test3", "Test3", idc2);
	Student student06("Test4", "Test4", idc1);
	Group gr1957("1957");
	gr1957.addStudent(student02);
	gr1957.addStudent(student03);
	gr1957.addStudent(student04);
	gr1957.addStudent(student05);
	gr1957.addStudent(student06);
	int k = gr1957.getSize();
	gr1957.GroupSort();
	cout << "In Group " << gr1957.getSize() << " " << k << " p." << endl;
	gr1957.GroupOut();
	gr1957.delStudent(student04);
	gr1957.delStudent(gr1957.findStudent("Test4", "Test4"));

}
void lab15_2() {
	lab15_1();
}

void test15() {
	StudentGrade student1 = StudentGrade("Test1", '1');
	StudentGrade student2 = StudentGrade("Test2", '2');
	map<string, char> map_student;
	map_student[student1.name] = student1.grade;
	map_student[student2.name] = student2.grade;
	for (const auto& element : map_student)
		cout << element.first << " - " << element.second << std::endl;
}


void demo1() {
	A a1;
	A a2(10);
	A a3 = a2;
	a1 = a3;
	a2 = A(20);
	const A a4(5);
	for (int i = 0; i < a2.size(); i++)
	{
		cout << a4[i] << endl;
	}
}

void demo2() {
	// add to Distance.h
}

void demo3() {
	Point pt1(1, 1);
	Point pt2(2, 2);
	Point pt3;
	pt3 = pt1 + pt2;
	pt2 += pt1;
	pt3 = pt1 + 5;
}

void demo4() {
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
}