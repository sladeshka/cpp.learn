#include "Distance.h"
#include "Time.h"

using namespace std;

void Distance::getdist()
{
	cout << "\nEnter number number: ";
	cin >> feet;
	cout << "\Enter number of inches: ";
	cin >> inches;
}
void Distance::showdist()
{
	cout << feet << "\" - " << inches << "\"\n";
}