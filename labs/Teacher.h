#pragma once
#include <string>
#include "Human.h"
#include <iostream>

using namespace std;

class Teacher : public Human
{
public:
	Teacher(string last_name, string name, string second_name, unsigned int work_time) 
		: Human(last_name, name, second_name) 
	{
		this->work_time = work_time;
	}
	unsigned int get_work_time()
	{
		return this->work_time;
	}

private:
	unsigned int work_time;
};