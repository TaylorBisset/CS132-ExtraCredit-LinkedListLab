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


int main()
{
    std::cout << "Hello World!\n";
}
