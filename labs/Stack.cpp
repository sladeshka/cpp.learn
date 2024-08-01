#include "Stack.h"

Stack::Stack()
{
	reset();
}

void Stack::reset()
{
	length = 0;
	for (int i = 0; i < 10; i++)
		arr[i] = 0;
}

void Stack::push(int value)
{
	arr[length] = value;
	length++;
}

void Stack::pop()
{
	if (length > 0) {
		arr[length - 1];
		arr[length - 1] = 0;
		length--;
	}
}

void Stack::print()
{
	cout << "( ";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	std::cout << ")" << std::endl;
}
