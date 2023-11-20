#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

int main()
{
    Node *top;
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *forth = new Node();
    Node *five = new Node();
    top = first;
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = forth;
    forth->data = 4;
    forth->next = five;
    five->data = 5;
    five->next = NULL;
    Node *ptr = top;
    while (ptr != NULL)
    {
        cout << "DATA of Nodes is " << ptr->data << endl;
        ptr = ptr->next;
    }
    delete first, second, forth, five, third;

    return 0;
}