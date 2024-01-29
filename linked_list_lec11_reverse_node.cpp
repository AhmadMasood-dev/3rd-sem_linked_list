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
    Node *ptr1;
 
    ptr1 = head;
    int size;
    cout << "Enter size of nodes  ";
    cin >> size;

    for (int i = 1; i <= size; i++)
    {
        Node *newNode = new Node();
        cout << "Enter the value of Node " << i << " is : ";
        cin >> newNode->data;
        newNode->next = NULL;
        ptr1->next = newNode;
        ptr1 = ptr1->next;
    }
    cout << "--------------------------------\n";
    int point = 1;
    Node *newptr;
    newptr = head->next;
    Node *temp;
    Node *temp2;
    while (newptr != NULL)
    {
        temp = newptr->next;

        if (point == 1)
        {
            newptr->next = NULL;
            temp2 = newptr;
            point++;
        }
        else
        {
            newptr->next = temp2;
            temp2 = newptr;
        }

        newptr = temp;
    }

    Node *ptr = temp2;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    delete head;

    delete temp2;
    
    delete ptr1;
   

    return 0;
}