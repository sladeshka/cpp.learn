#pragma once
#include <string>
#include "Human.h"
#include <iostream>

using namespace std;

class Teacher : public Human
{
public:
	Teacher() {}
	Teacher(string last_name, string name, string second_name) : Human(last_name, name, second_name) {
		this->profession = "Teacher";
	}
	Teacher(string last_name, string name, string second_name, unsigned int work_time) 
		: Human(last_name, name, second_name) 
	{
		this->work_time = work_time;
	}
	unsigned int get_work_time()
	{
		return this->work_time;
	}

	void set_group(string group)
	{
		this->group = group;
	}

	string get_group()
	{
		return this->group;
	}

	string getData()
	{
		return Human::getData() + " group: " + this->get_group() + " phone: " + this->get_phone();
	}

private:
	unsigned int work_time;
	string group;
};