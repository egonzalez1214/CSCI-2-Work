// CSCI 2 - 9. Number Array Class.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include "MyArray.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    MyArray ourArray(5);
    ourArray.StoreNum(0, 1.4);
    ourArray.StoreNum(1, 2.3);
    ourArray.StoreNum(2, 3.13);
    ourArray.StoreNum(3, 6.66);
    ourArray.StoreNum(4, 7.711);
    cout << endl;

    ourArray.RetrieveNum();
    cout << endl;
    ourArray.HighestNum();
    ourArray.LowestNum();
    ourArray.Average();
}
