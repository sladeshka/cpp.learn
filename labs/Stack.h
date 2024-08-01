#pragma once
#include <iostream>

using namespace std;

class Stack
{
public:
	int arr[10];
	int length;
	Stack();
	void reset();
	void push(int value);
	void pop();
	void print();
};