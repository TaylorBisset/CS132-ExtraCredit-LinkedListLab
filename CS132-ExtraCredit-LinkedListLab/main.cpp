// main.cpp

/*
Name:           Taylor Bisset
Section:        A
Program Name:   CS132-ExtraCredit-LinkedListLab

Description:    This C++ program implements a doubly linked list with functionalities like adding elements, 
                 iterating through the list, and testing link integrity. 
                The main function demonstrates these features with a sample list of ten elements.

Repo:           https://github.com/TaylorBisset/CS132-ExtraCredit-LinkedListLab

*/

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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

class DblLinkedList 
{
private:
    Node* head;
    Node* tail;
    Node* iterator;

public:
    DblLinkedList() : head(nullptr), tail(nullptr), iterator(nullptr) {}

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

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

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    // Function to reset the iterator to the beginning of the linked list
    void resetIterator()
    {
        iterator = head;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    // Function to check if there are more elements in the linked list to iterate over
    bool hasMore()
    {
        return iterator != nullptr;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    // Function to move the iterator to the next element in the linked list
    string next()
    {
        if (iterator == nullptr)
        {
            return ""; // or throw an exception indicating the end of the list
        }

        string value = iterator->data;
        iterator = iterator->next;
        return value;
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    // Function to test all the links in the linked list for specific conditions
    void testConnections()
    {
        // Check head->prev should be nullptr
        if (head != nullptr && head->prev != nullptr)
        {
            cerr << "Error: head->prev is not nullptr." << endl;
        }

        // Check tail->next should be nullptr
        if (tail != nullptr && tail->next != nullptr)
        {
            cerr << "Error: tail->next is not nullptr." << endl;
        }
        // Loop through and test one node at a time
        Node* temp = head;
        while (temp != nullptr && temp != tail)
        {
            // Test if you can travel to the next node and then back through the prev pointer
            if (temp->next != nullptr && temp->next->prev != temp)
            {
                cerr << "Error: Unable to loop from temp to next and then back to temp." << endl;
            }

            temp = temp->next;
        }
    }
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main()
{
    DblLinkedList list;
    list.push_back("1"); // insert back...into empty list
    list.push_back("2"); // insert back
    list.push_back("3");
    list.push_back("4");
    list.push_back("5");
    list.push_back("6");
    list.push_back("7");
    list.push_back("8");
    list.push_back("9");
    list.push_back("10");
    list.resetIterator();
    while (list.hasMore()) 
    {
        cout << list.next() << endl;
    }
    list.testConnections();
    system("pause");
    return 0;
}

/*

OUTPUT: 

1
2
3
4
5
6
7
8
9
10
Press any key to continue . . .

*/