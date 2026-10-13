#pragma once
#include <iostream>
#include <string>
using namespace std;

// remembering .h is for class declarations
// declaring my class MyStack with private and public members
class MyStack
{
private:
	// values are private
	string* stackArray;
	int stackSize;
	int top;
public:
	// function calls are public
	MyStack(int size);
	~MyStack();
	bool IsFull();
	bool IsEmpty();
	void Push(string);
	void Pop(string&);
	void PrintStack();
};

