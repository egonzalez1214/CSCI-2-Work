// CSCI 2 - 14. Stack ADT Singly Linked List.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
#include "MyStack.h"
using namespace std;

int main()
{
	MyStack stack;
	int choice;
	int value;

	do
	{
		cout << "--- Stack Menu ---" << endl;
		cout << left << setw(12) << "1. Push" << "3. Peek" << endl;
		cout << left << setw(12) << "2. Pop" << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "How will we manipulate the stack today?: ";
		cin >> choice;

		switch (choice)
		{
		case 1: // pushing to the stack
			cout << "What are we pushing into the stack?: ";
			cin >> value;
			stack.push(value);
			cout << endl;
			break;
		case 2: // popping from the stack
			cout << "Popping from the stack..." << endl;
			stack.pop();
			cout << endl;
			break;
		case 3: // peeking the stack
			cout << "Top value: " << stack.peek() << endl;
			cout << endl;
			break;
		case 4: // displaying the stack
			stack.display();
			break;
		case 5: // exiting the program
			cout << "Now terminating everything..." << endl;
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			cout << endl;
		}
	} while (choice != 5);
}
