#pragma once
#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

class Paperbook : public Item
{
private:
	int pages;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Enter number of pages: ";
		cin >> pages;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nPages:" << pages;
	}
};