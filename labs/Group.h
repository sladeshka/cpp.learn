#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "Student.h"

using namespace std;


class Group
{
public:
	Group(); 
	Group(string name)
	{
		this->name = name;
	}
	int  getSize();
	void addStudent(Student newStudent);
	void delStudent(Student oldStudent);
	Student findStudent(string, string);
	void GroupSort();
	void GroupOut();

	friend bool operator< (const Student&, const Student&);
	friend bool operator> (const Student&, const Student&);
	friend bool operator== (const Student&, const Student&);
	friend bool operator!= (const Student&, const Student&);

private:
	string name;
	list <Student> masSt;
	list <Student>::iterator iter;
};