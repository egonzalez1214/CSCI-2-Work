#include "MyStack.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
MyStack::MyStack()
{
	top = nullptr;
}

// empty check
bool MyStack::isEmpty()
{
	return top == nullptr;
}

// pushing to the stack
void MyStack::push(int value)
{
	// declaring my pointer
	Node* newNode = new Node;

	newNode->data = value;
	newNode->next = top;

	top = newNode;
}

// popping from the stack
void MyStack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty. Nothing to pop." << endl;
		return;
	}

	Node* temp = top;
	top = top->next;

	cout << "Popped: " << temp->data << endl;
	delete temp;
}

// peek the stack
int MyStack::peek()
{
	if (isEmpty())
	{
		cout << "Stack is empty. Nothing to peek." << endl;
		return -1; // or throw an exception
	}

	return top->data;
}

void MyStack::display()
{
	// check if the stack is empty
	if (isEmpty())
	{
		cout << "Stack is empty." << endl;
		return;
	}

	// print the stack
	Node* current = top;
	cout << "--- MyStack ---" << endl;
	while (current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
	cout << endl;
}

MyStack::~MyStack()
{
	while (top != nullptr)
	{
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}