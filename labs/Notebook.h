#pragma once
#include <string>
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Colleague.h"
#include <iostream>

class Notebook
{
public:
	Notebook() {}
	~Notebook() {}
	void run()
	{
		string paragraph = "0";
		while (paragraph != "exit")
		{
			system("cls");
			showMenu(paragraph);
			cin >> paragraph;
		}
	}

	void showMenu(string paragraph) {
		system("cls");
		string last_name;
		string name;
		string second_name;
		string phone;
		string position;
		string group;
		if (paragraph == "0") {
			cout << "1. Add contact\n";
			cout << "2. Show contacts\n";
			cout << "Select a number:\n";
			cout << "or enter exit\n";
		}
		else if (paragraph == "1") {
			cout << "Colleague\n";
			cout << "Student\n";
			cout << "Teacher\n";
			cout << "Enter the name of the group:\n";
		}
		else if (paragraph == "2") {
			for (int i = 0; i < contacts.size(); i++)
			{
				cout << contacts[i]->getData() << endl;
			}
			cout << "enter 0\n";
		}
		else if (paragraph == "Colleague") {
			cout << "enter name, last name, and second name\n";
			cin >> name >> last_name >> second_name;
			cout << "enter position\n";
			cin >> position;
			cout << "enter phone\n";
			cin >> phone;
			Colleague* colleague = new Colleague(last_name, name, second_name, position);
			colleague->set_phone(phone);
			contacts.push_back(colleague);
			saveToFile();
			cout << "enter 0\n";
		}
		else if (paragraph == "Student") {
			cout << "enter name, last name, and second name\n";
			cin >> name >> last_name >> second_name;
			cout << "enter group\n";
			cin >> group;
			cout << "enter phone\n";
			cin >> phone;
			Student* student = new Student(last_name, name, second_name);
			student->set_group(group);
			student->set_phone(phone);
			contacts.push_back(student);
			saveToFile();
			cout << "enter 0\n";
		}
		else if (paragraph == "Teacher") {
			cout << "enter name, last name, and second name\n";
			cin >> name >> last_name >> second_name;
			cout << "enter group\n";
			cin >> group;
			cout << "enter phone\n";
			cin >> phone;
			Teacher* teacher = new Teacher(last_name, name, second_name);
			teacher->set_group(group);
			teacher->set_phone(phone);
			contacts.push_back(teacher);
			saveToFile();
			cout << "enter 0\n";
		}
		else if (paragraph == "exit") {
			exit(0);
		}
		else {
			cout << "Invalid input\n";
			cout << "enter 0\n";
		}
	}

	void saveToFile()
	{
		ofstream file("notebook.txt", ios::app);
		if (!file) {
			std::cout << "ERORR\n";
		}
		for (const auto& item : contacts) {
			file << item->getData() << endl;
		}
		cout << "Added\n";
		file.close();
	}
private:
	vector<Human*> contacts;
};