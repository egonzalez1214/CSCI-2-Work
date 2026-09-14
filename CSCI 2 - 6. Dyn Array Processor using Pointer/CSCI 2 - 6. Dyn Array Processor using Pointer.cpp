// CSCI 2 - 6. Dyn Array Processor using Pointer.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
using namespace std;

// function prototypes
void SquareElements(int size, int* dynArray);
void FillDynArray(int size, int* dynArray);

int main()
{
	// declaring our dynamic variable
	int size;
	cout << "How many elements intergers do you want to store: ";
	cin >> size;
	cout << endl;

	// pointer to the dynaic array
	int* dynArray = new int[size];
	// fuction to fill the array
	FillDynArray(size, dynArray);
	// function that squares and prints squared array
	SquareElements(size, dynArray);
	// deleting our dynamic array
	delete[] dynArray;
}

// dont need the [] brackets when referencing the pointer...
void FillDynArray(int size, int* dynArray)
{
	// for loop to fill in our array elements
	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i << ": ";
		cin >> dynArray[i];
	}
	cout << endl;

	// extra for loop to print the array out neatly
	for (int i = 0; i < size; i++)
	{
		cout << "[" << dynArray[i] << "]";
	}
	cout << endl << endl;
}

// again, dont need the [] brackets to reference my pointer...
void SquareElements(int size, int* dynArray)
{
	// function to square my element (multiply it by itself) and print
	// ... using pointer arithmetic
	for (int i = 0; i < size; i++)
	{
		*(dynArray + i) = *(dynArray + i) * *(dynArray + i);
		cout << "[" << dynArray[i] << "]";
	}
	cout << endl;
}