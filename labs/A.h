#pragma once
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class A {
public:
    A();
    A(int);
    A(const A&);
    ~A();
    int size() const;
    int& operator[](int&) const;
    A& operator=(const A&);

private:
    int* arr;
    int length;
};