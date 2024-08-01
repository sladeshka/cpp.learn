#include <string> 
#include <fstream>
#include "Student.h"
#include "IdCard.h"
#include <iostream>

using namespace std;

Student::Student()
{
    Student::save();
}

Student::Student(IdCard* c)
{
    iCard = c;
}

Student::Student(string name, string last_name)
{
    Student::set_name(name);
    Student::set_last_name(last_name);
}

Student::Student(string name, string last_name, IdCard* id)
{
    Student::set_name(name);
    Student::set_last_name(last_name);
    Student::setIdCard(id);
}

void Student::save()
{
    ofstream fout("students.txt", ios::app);

    fout << Student::get_name() << " "
        << Student::get_last_name() << " ";
    for (int i = 0; i < 5; ++i) {
        fout << Student::scores[i] << " ";
    }

    fout << endl;
    fout.close();
}

IdCard Student::getIdCard()
{
    return *iCard;
}

void Student::display()
{
    cout << Student::get_last_name() << " " << Student::get_name() << endl;
}

bool operator== (const Student& p1, const Student& p2)
{
    return (p1.name == p2.name && p1.last_name == p2.last_name) ? true : false;
}
bool operator< (const Student& p1, const Student& p2)
{
    if (p1.last_name == p2.last_name)
        return (p1.name < p2.name) ? true : false;
    return (p1.last_name < p2.last_name) ? true : false;
}
bool operator!= (Student& p1, Student& p2)
{
    return !(p1 == p2);
}
bool operator> (Student& p1, Student& p2)
{
    return !(p1 < p2) && !(p2 == p2);
}

void Student::setIdCard(IdCard* c)
{
    iCard = c;
}

void Student::set_name(string student_name)
{
    Student::name = student_name;
}
string Student::get_name()
{
    return Student::name;
}
void Student::set_last_name(string student_last_name)
{
    Student::last_name = student_last_name;
}
string Student::get_last_name()
{
    return Student::last_name;
}
void Student::set_scores(int scores[])
{
    for (int i = 0; i < 5; ++i) {
        if (scores[i] > 5)
            throw ExScore("в функции set_scores()", scores[i]);
        scores[i] = scores[i];
    }
}
void Student::set_average_score(double ball)
{
    Student::average_score = ball;
}
/*double Student::get_average_score()
{
    return Student::average_score;
}*/
