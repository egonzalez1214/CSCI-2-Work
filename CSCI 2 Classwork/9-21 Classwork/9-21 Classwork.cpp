// 9-21 Classwork.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
#include <string>
using namespace std;

class UnsortedList {
private:
    int data[50];
    int length;

public:
    // TODO: Constructor initializes length to 0
    UnsortedList()
    {
        // ez
        length = 0;
    }
    // TODO: void insertItem(int item)
    void InsertItem(int item)
    {
        // insert our data accordingly
        if (length < 50)
        {
            data[length] = item;
            length++;
        }
    }
    // TODO: void deleteItem(int index)
    void DeleteItem(int index)
    {
        if (index >= 0 && index < length)
        {
            // for loop shifts the selected index to the end of the list
            for (int i = index; i < length - 1; i++)
            {
                data[i] = data[i + 1];
            }
            // we shorten length by one after the for loop
            // basically deleting the last slot (our selected index)
            length--;
        }
    }
    // TODO: void displayList() const
    void DisplayList()
    {
        // ez print
        for (int i = 0; i < length; i++)
        {
            cout << "List[" << i << "]: " << data[i] << endl;
        }
    }
};
int main() {
    UnsortedList list;
    // Insert some values
    list.InsertItem(10);
    list.InsertItem(25);
    list.InsertItem(30);
    list.InsertItem(5);

    // print the list
    cout << "Current List:\n";
    list.DisplayList();

    // get user index to delete
    int index;
    cout << "\nEnter an index to delete: ";
    cin >> index;
    // call functino to delete it
    list.DeleteItem(index);

    // print the list
    cout << "\nUpdated List:\n";
    list.DisplayList();
}