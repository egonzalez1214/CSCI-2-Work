// CSCI 2 - 15. Dynamic Queue of Double Values.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include "DynamicQueue.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // dynamic queue object
    DynamicQueue myQueue;
	int response;
    double value;

    // adding values to the queue
	cout << "Adding starter values to the queue..." << endl;
	myQueue.Enqueue(10.792);
	myQueue.Enqueue(20.236);
    myQueue.Enqueue(30.412);

    // menu on what to do
	cout << "What would you like to do to the queue?" << endl;
	cout << setw(20) << left << "1. Enqueue another value."
         << "2. Dequeue a value." << endl;
	cout << setw(20) << left << "3. Clear the queue."
		 << "4. Exit the program." << endl;
	cin >> response;

	switch(response)
	{
	case 1:
		cout << "Enter a value to enqueue: ";
		cin >> value;
		myQueue.Enqueue(value);
		break;
	case 2:
		myQueue.Dequeue(value);
		cout << "Dequeued value: " << value << endl;
		break;
	case 3:
		myQueue.Clear();
		cout << "Queue cleared." << endl;
		break;
	case 4:
		cout << "Exiting the program." << endl;
		break;
	default:
		cout << "Invalid option. Please type 1, 2, 3, or 4." << endl;
	}
}
