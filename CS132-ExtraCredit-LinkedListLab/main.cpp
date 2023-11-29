// main.cpp

#include <iostream>
#include <string>

using namespace std;

class Node 
{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string value) : data(value), next(nullptr), prev(nullptr) {}
};

class DblLinkedList 
{
private:
    Node* head;
    Node* tail;
    Node* iterator;

public:
    DblLinkedList() : head(nullptr), tail(nullptr), iterator(nullptr) {}
    // Function to add an element to the end of the linked list
    void push_back(string str)
    {
        Node* newNode = new Node(str);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // Function to reset the iterator to the beginning of the linked list
    void resetIterator()
    {
        iterator = head;
    }
    // Function to check if there are more elements in the linked list to iterate over
    bool hasMore()
    {
        return iterator != nullptr;
    }

};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main()
{
    cout << "Hello World!\n";
}
