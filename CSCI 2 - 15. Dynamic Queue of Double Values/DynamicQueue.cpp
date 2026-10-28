#include "DynamicQueue.h"
#include <iostream>
#include <string>
using namespace std;

// constructor body
DynamicQueue::DynamicQueue()
{
	// set front / rear to nullptr
	front = nullptr;
	rear = nullptr;
}

// destructor body
DynamicQueue::~DynamicQueue()
{
	// clear the queue
	Clear();
}

// check for empty function
bool DynamicQueue::IsEmpty() const
{
	return (front == nullptr);
}

// enqueue function
void DynamicQueue::Enqueue(double value)
{
	// create a new node
	QueueNode* newNode = new QueueNode;
	newNode->value = value;
	newNode->next = nullptr;
	// check if queue is empty
	if (IsEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		// old rear to new node
		rear->next = newNode;
		// new node is now rear
		rear = newNode;
	}
}

// dequeue function
void DynamicQueue::Dequeue(double& value)
{
	// check if queue is empty
	if (IsEmpty())
	{
		cout << "The queue is empty. Nothing to dequeue." << endl;
		return;
	}
	else
	{
		// store value to be dequeued
		value = front->value;
		// create temporary pointer to front node
		QueueNode* temp = front;
		// move front to next
		front = front->next;
		// delete old front
		delete temp;
	}
}

// clear function
void DynamicQueue::Clear()
{
		double value;
		// dequeue values until empty
		while (!IsEmpty())
		{
			Dequeue(value);
		}
}
