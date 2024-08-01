#pragma once
#include <string> 
#include "Human.h"
#include "IdCard.h"
#include <vector>
using namespace std;

class Student : public Human
{
public:
	Student();
	Student(IdCard*);
	Student(string, string);
	Student(string, string, IdCard*);
	Student(string last_name, string name, string second_name, vector<int> scores) : Human(last_name, name, second_name) {
		this->scores = scores;
	}
	void save();
	void set_name(string);
	string get_name();
	void set_last_name(string);
	string get_last_name();
	void set_scores(int[]);
	void set_average_score(double);
	//double get_average_score();
	float get_average_score()
	{
		unsigned int count_scores = this->scores.size();
		unsigned int sum_scores = 0;
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i) {
			sum_scores += this->scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		return average_score;
	}
	void setIdCard(IdCard* c);
	IdCard getIdCard();
	class ExScore
	{
	public:
		string origin;
		int iValue;

		ExScore(string on, int sc)
		{
			origin = on;
			iValue = sc;
		}
	};
	friend bool operator< (const Student&, const Student&);
	friend bool operator> (const Student&, const Student&);
	friend bool operator== (const Student&, const Student&);
	friend bool operator!= (const Student&, const Student&);
	void display();
	class compareStudent
	{
	public:
		bool operator() (const Student* ptrSt1, const Student* ptrSt2) const
		{
			return *ptrSt1 < *ptrSt2;
		}
	};

private:
	//int scores[5];
	double average_score;
	string name;
	string last_name;
	IdCard* iCard;
	vector<int> scores;
};
