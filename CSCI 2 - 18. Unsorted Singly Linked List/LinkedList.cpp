#include "LinkedList.h"

#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    DestroyRecursive(head);
}

Node* LinkedList::GetHead()
{
    return head;
}

void LinkedList::InsertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::DisplayRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return;
    }

    // display current node
    cout << current->data << " ";

    // recursive call
    DisplayRecursive(current->next);
}

int LinkedList::CountRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return 0;
    }
    // recursive call and count
    return 1 + CountRecursive(current->next);
}

int LinkedList::SumRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return 0;
	}
}

int LinkedList::LargestRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return INT_MIN; // Return the smallest integer value
    }
    // recursive call to find the largest in the rest of the list
    int maxInRest = LargestRecursive(current->next);
    // return the maximum of current node's data and the largest in the rest
    return (current->data > maxInRest) ? current->data : maxInRest;
}

bool LinkedList::SearchRecursive(Node* current, int key)
{
    // base case
    if (current == nullptr)
    {
        return false;
    }
    // check if current node's data matches the key
    if (current->data == key)
    {
        return true;
    }
    // recursive call to search in the rest of the list
    return SearchRecursive(current->next, key);
}

void LinkedList::ReverseDisplayRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return;
    }
    // recursive call to display the rest of the list
    ReverseDisplayRecursive(current->next);
    // display current node after returning from recursion
    cout << current->data << " ";
}

void LinkedList::DestroyRecursive(Node* current)
{
    // base case
    if (current == nullptr)
    {
        return;
    }
    // recursive call to destroy the rest of the list
    DestroyRecursive(current->next);
    // delete current node
    delete current;
}