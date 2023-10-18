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
    top = first;
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    Node *newptr, *p;
    newptr = top;
    p = top;
    int count = 0;
    while (newptr != NULL)
    {
        newptr = newptr->next;
        count++;
    }
    int location;
    cout << "Enter a place where u want to enter new node between 2 - " << count << "\t";
    cin >> location;
    while (location < 2 || location > count)
    {
        cout << "new node must be between 2 - " << count << "\nEnter again\t";
        cin >> location;
    }

    for (int i = 2; i < location; i++)
    {
        p = p->next;
    }
    Node *temp;
    temp = p->next;
    Node *newNode = new Node();
    p->next = newNode;
    newNode->data = 4;
    newNode->next = temp;   
    Node *ptr = top;
    while (ptr != NULL)
    {
        cout << "data 1 is : " << ptr->data << endl;
        ptr = ptr->next;
    }

    return 0;
}