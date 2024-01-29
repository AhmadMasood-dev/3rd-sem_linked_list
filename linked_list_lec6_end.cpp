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
    Node *top = new Node();
    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;

    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3; 
    third->next = NULL;

    top = first;
    Node *newptr;
    newptr = top;
    Node *newnode = new Node();
    newnode->data = 4;
    newnode->next = NULL;
    while (newptr->next != NULL)
    {
        newptr = newptr->next;
    }
    newptr->next = newnode;
    Node *ptr;
    ptr = top;

    while (ptr != NULL)
    {
        cout << "data 1 is : " << ptr->data << endl;
        ptr = ptr->next;
    }
    delete top, first, second, third, newnode;
    return 0;
}