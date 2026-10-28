// CSCI 2 - 18. Unsorted Singly Linked List.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include "LinkedList.h" 
#include <iostream>
using namespace std;

int main()
{
    LinkedList list;

    list.InsertEnd(10);
    list.InsertEnd(25);
    list.InsertEnd(8);
    list.InsertEnd(35);
    list.InsertEnd(12);

    cout << "Display: ";
    list.DisplayRecursive(list.GetHead());

    cout << "\nCount: "
        << list.CountRecursive(list.GetHead());

    cout << "\nSum: "
        << list.SumRecursive(list.GetHead());

    cout << "\nLargest: "
        << list.LargestRecursive(list.GetHead());

    cout << "\nSearch for 8: ";

    if (list.SearchRecursive(list.GetHead(), 8))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\nReverse Display: ";
    list.ReverseDisplayRecursive(list.GetHead());

    return 0;
}