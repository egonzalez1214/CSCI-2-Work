#pragma once

struct Node
{
	int data;
	Node* next;
};

class MyStack
{
private:
	Node* top;

public:
	MyStack();
	~MyStack();
	bool isEmpty();
	void push(int value);
	void pop();
	int peek();
	void display();
};