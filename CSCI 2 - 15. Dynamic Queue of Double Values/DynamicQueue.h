#pragma once
#include <iostream>
#include <string>
using namespace std;

class DynamicQueue
{
private:
	// the node structure
	struct QueueNode
	{
		double value;
		// pointer to the next node
		QueueNode* next;
	};
	// pointers to the front / back of the queue
	QueueNode* front;
	QueueNode* rear;

public:
	// constructor
	DynamicQueue();
	// destructor
	~DynamicQueue();
	// queue operations
	void Enqueue(double value);
	void Dequeue(double& value);
	// function to check if empty
	bool IsEmpty() const;
	// function to clear queue
	void Clear();
};