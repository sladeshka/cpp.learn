#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item
{
private:
	string title;
	double price;
public:
	virtual void getdata()
	{
		cout << "\nEnter title: ";
		cin >> title;
		cout << "Enter price: ";
		cin >> price;
	}
	virtual void putdata()
	{
		cout << "\nHeading: " << title;
		cout << "\nPrice: " << price;
	}
};