#pragma once

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

    // Recursive helper used by destructor
    void DestroyRecursive(Node* current);

public:
    LinkedList();
    ~LinkedList();
    void InsertEnd(int value);

    // Recursive Functions
    void DisplayRecursive(Node* current);
    int CountRecursive(Node* current);
    int SumRecursive(Node* current);
    int LargestRecursive(Node* current);
    bool SearchRecursive(Node* current, int key);
    void ReverseDisplayRecursive(Node* current);

    Node* GetHead();
};

