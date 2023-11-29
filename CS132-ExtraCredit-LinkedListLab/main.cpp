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
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main()
{
    cout << "Hello World!\n";
}
