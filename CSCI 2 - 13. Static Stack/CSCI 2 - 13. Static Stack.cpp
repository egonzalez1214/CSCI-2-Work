// CSCI 2 - 13. Static Stack.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

int main()
{
	// create a stack of size 5
	MyStack stack(5);
	// push 5 strings onto the stack
	// print string as pushed for vision
	stack.Push("Bill Microsoft");
	cout << "Pushed: Bill Microsoft" << endl;
	stack.Push("Steve Apple");
	cout << "Pushed: Steve Apple" << endl;
	stack.Push("Larry Google");
	cout << "Pushed: Larry Google" << endl;
	stack.Push("Linus Linux");
	cout << "Pushed: Linus Linux" << endl;
	stack.Push("Mark Facebook");
	cout << "Pushed: Mark Facebook" << endl;
	cout << endl;
	
	string value;
	// stacks are LIFO, so pop last value pushed
	stack.Pop(value);
	// print popped
	cout << "Popped: " << value << endl;
	// pop second to last value pushed
	stack.Pop(value);
	// print popped
	cout << "Popped: " << value << endl;
	cout << endl;

	// print remaining stack
	cout << "--- Remaining Stack ---" << endl;
	stack.PrintStack();

	return 0;
}
