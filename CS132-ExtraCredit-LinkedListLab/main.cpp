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

    // Function to test all the links in the linked list for specific conditions
    void testConnections()
    {
        // Check head->prev should be nullptr
        if (head != nullptr && head->prev != nullptr)
        {
            cout << "Error: head->prev is not nullptr." << endl;
        }

        // Check tail->next should be nullptr
        if (tail != nullptr && tail->next != nullptr)
        {
            cout << "Error: tail->next is not nullptr." << endl;
        }

        // Loop through and test one node at a time
        Node* temp = head;
        while (temp != nullptr && temp != tail)
        {
            // Test if you can travel to the next node and then back through the prev pointer
            if (temp != temp->next->prev)
            {
                cout << "Error: Unable to loop from temp to next and then back to temp." << endl;
            }

            temp = temp->next;
        }
    }
};

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int main()
{
    cout << "Hello World!\n";
}
