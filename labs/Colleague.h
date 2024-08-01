#pragma once
#include <string> 
#include "Human.h"
#include "IdCard.h"
#include <vector>
using namespace std;

class Colleague : public Human
{
public:
    Colleague() : Human() {}
    Colleague(string last_name, string name, string second_name, string position) : Human(last_name, name, second_name)
    {
        this->profession = "Colleague";
        this->position = position;
    }
    string get_position() {
        this->position;
    }
    string getData()
    {
        return Human::getData() + " position " + this->position + " phone: " + this->get_phone();
    }
private:
    string position;
};