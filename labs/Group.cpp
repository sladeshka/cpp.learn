#include "Group.h"

Group::Group()
{
}

int Group::getSize()
{
	return masSt.size();
}

void Group::addStudent(Student newStudent)
{
	masSt.push_back(newStudent);
}

void Group::delStudent(Student oldStudent)
{
	masSt.remove(oldStudent);
}

Student Group::findStudent(string searchName, string searchLastName)
{
	Student temp(searchName, searchLastName);
	iter = find(masSt.begin(), masSt.end(), temp);
	return(*iter);
}

void Group::GroupSort()
{
}

void Group::GroupOut()
{
	iter = masSt.begin();
	while (iter != masSt.end()) 
		(*iter++).display();
}
