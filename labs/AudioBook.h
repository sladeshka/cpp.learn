#pragma once
#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

class AudioBook : public Item
{
private:
	double time;
public:
	void getdata()
	{
		Item::getdata();
		cout << "Enter playing time: ";
		cin >> time;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\nPlaying time: " << time;
	}
};