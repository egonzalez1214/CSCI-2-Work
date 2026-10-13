// 9-23 Classwork.cpp
// This file contains the 'main' function.
// Program execution begins and ends there.

#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
    LinkedList();
    void Append(int value);
    void DeleteValue(int value);
    void PrintList() const;
};

LinkedList::LinkedList() : head(nullptr)
{
}

void LinkedList::Append(int value)
{
    Node* newNode = new Node{ value, nullptr };
    {
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

void LinkedList::DeleteValue(int value)
{
    Node* newNode = new Node{ value, nullptr };
    if (!nullptr)
    {

    }
    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* current = head;
    while(current->next != nullptr)
    {
        if (current->next->data == value)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        current = current->next;
    }
}

void LinkedList::PrintList() const
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << "- " << current->data << " -" << endl;
        current = current->next;
    }
}

int main() {
    LinkedList list;
    // TODO: Append five values
    cout << "First we append five values and print..." << endl;
    list.Append(10);
    list.Append(20);
    list.Append(30);
    list.Append(40);
    list.Append(50);

    // TODO: Print the list
    list.PrintList();
    cout << endl;

    // TODO: Ask user for a value to delete
    cout << "Select one of the five values to delete: ";
    int value;
    cin >> value;
    // TODO: Call DeleteValue
    list.DeleteValue(value);

    // TODO: Print updated list
    list.PrintList();

    return 0;
}
