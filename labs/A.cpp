#include "A.h"
using namespace std;

A::A()
{
    length = 0;
    arr = {};
}

A::A(int len)
{
    length = len;
    arr = new int[len];
    for (int i = 0; i < length; i++)
        arr[i] = 0;
}

A::A(const A& _arr)
{
    length = _arr.length;
    arr = new int[length];
    for (int i = 0; i < length; i++)
        arr[i] = _arr.arr[i];
}

A::~A()
{
    delete arr;
}

int A::size() const
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        count++;
    }
    return count;
}

int& A::operator[](int& n) const
{
    return arr[n];
}

A& A::operator=(const A& ar)
{
    if (length > 0)
        delete[] arr;
    length = ar.length;
    arr = new int[length];
    for (int i = 0; i < length; i++)
        arr[i] = ar.arr[i];
    return *this;
}
