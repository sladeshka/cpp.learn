#pragma once
#include <string> 
#include <sstream>
using namespace std;

class Human {
public:
	Human() {};
	Human(string last_name, string name, string second_name)
	{
		this->name = name;
		this->last_name = last_name;
		this->second_name = second_name;
	}
	string get_full_name()
	{
		ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;
		return full_name.str();
	}
	virtual unsigned int get_work_time();
	virtual float get_average_score();


private:
	string name;
	string last_name;
	string second_name;
};