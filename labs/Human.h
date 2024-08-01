#pragma once
#include <string> 
#include <sstream>
using namespace std;

class Human {
public:
	string profession;
	Human() {};
	Human(string last_name, string name)
	{
		this->name = name;
		this->last_name = last_name;
		this->profession = typeid(*this).name();
	}
	Human(string last_name, string name, string second_name)
	{
		this->name = name;
		this->last_name = last_name;
		this->second_name = second_name;
		this->profession = typeid(*this).name();
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
	string get_name() {
		return this->name;
	}
	string get_last_name() {
		return this->last_name;
	}
	string get_second_name() {
		return this->second_name;
	}
	string get_phone() {
		return this->phone;
	}
	string get_profession() {
		return this->profession;
	}
	virtual string getData() { 
		return "name: " + this->get_name() + " last name: " + this->get_last_name() + " second name: " + this->get_second_name() + " profession: " + this->get_profession();
	};
	void set_phone(string phone) {
		this->phone = phone;
	}
private:
	string name;
	string last_name;
	string second_name;
	string phone;
};