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
    Node *head = new Node();
    Node *head_ptr;
    head_ptr = head;

    int size = 3;
    cout << "Enter size of nodes 1 ";
     cin >> size;

    for (int i = 1; i <= size; i++)
    {
        Node *newNode = new Node();
        cout << "Enter the value of Node " << i << " is : ";
        cin >> newNode->data; 
        newNode->next = NULL;
        head_ptr->next = newNode;
        head_ptr = head_ptr->next;
    }
    cout << "--------------------------------\n";
    cout << "Enter a size for node 2  ";
     cin >> size;

    for (int i = 1; i <= size; i++)
    {
        Node *newNode = new Node();
        cout << "Enter the value of Node " << i << " is : ";
        cin >> newNode->data;
        newNode->next = NULL;
        head_ptr->next = newNode;
        head_ptr = head_ptr->next;
    }
    cout << "--------------------------------\n";

    Node *ptr2 = head->next;
    int value;
    Node *i, *j;
    for (i = ptr2; i->next != NULL; i=i->next)
    {
        for (j = i->next; j != NULL; j=j->next)
        {
            if (i->data>j->data)
            {
                 
                value = i->data;
                i->data = j->data;
                j->data = value;
            }
            
        }
    }
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    delete head;

    delete ptr,ptr2,head_ptr;

    return 0;
}