#include "MyStack.h"
#include <iostream>
#include <string>
using namespace std;

// the .cpp file is for function definitions the "substance"
// MyStack constructor
MyStack::MyStack(int size)
{
	stackSize = size;
	stackArray = new string[stackSize];
	top = -1;
}

// MyStack destructor
MyStack::~MyStack()
{
	delete[] stackArray;
}

// check if stack is full
bool MyStack::IsFull()
{
	return top == stackSize - 1;
}

// check if stack is empty
bool MyStack::IsEmpty()
{
	return top == -1;
}

// push a value onto the stack
void MyStack::Push(string value)
{
	if (!IsFull())
	{
		stackArray[++top] = value;
	}
}

// pop a value off the stack
void MyStack::Pop(string& value)
{
	if (!IsEmpty())
	{
		value = stackArray[top--];
	}
}

// print the stack
void MyStack::PrintStack()
{
	if (!IsEmpty())
	{
		for (int i = top; i >= 0; i--)
		{
			cout << stackArray[i] << endl;
		}
	}
}