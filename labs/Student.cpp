#include <string> 
#include <fstream>
#include "student.h"
#include "IdCard.h"

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
double Student::get_average_score()
{
    return Student::average_score;
}


