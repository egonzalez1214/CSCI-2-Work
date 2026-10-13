#include "MyArray.h"
#include <iostream>
#include <string>
using namespace std;

MyArray::MyArray(int arraySize)
{
	size = arraySize;
	arrayPtr = new float[size];
}

MyArray::~MyArray()
{
	delete[] arrayPtr;
}

void MyArray::StoreNum(int index, float value)
{
	arrayPtr[index] = value;
	cout << "Stored " << value << " in index " << index << endl;
}

void MyArray::RetrieveNum()
{
	for (int i = 0; i < size; i++)
	{
		cout << "The value of ourArray[" << i << "] is: " << arrayPtr[i] << endl;
	}
}

void MyArray::HighestNum()
{
	float highNum = arrayPtr[0];
	for (int i = 0; i < size; i++)
	{
		if (arrayPtr[i] > highNum)
		{
			highNum = arrayPtr[i];
		}
	}
	cout << "The highest value in our array is: " << highNum << endl;
}

void MyArray::LowestNum()
{
	float lowNum = arrayPtr[0];
	for (int i = 0; i < size; i++)
	{
		if (arrayPtr[i] < lowNum)
		{
			lowNum = arrayPtr[i];
		}
	}
	cout << "The lowest value in our array is: " << lowNum << endl;
}

void MyArray::Average()
{
	double sumNums = 0;
	for (int i = 0; i < size; i++)
	{
		sumNums += arrayPtr[i];
	}
	double numsAvg = sumNums / size;
	cout << "The average value of our array is: " << numsAvg << endl;
}