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
    int size;
    cout << "Enter number of nodes : ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter a data of Node  " << i << " is : ";
        Node *newnode = new Node();
        cin >> newnode->data;
        newnode->next = NULL;
        head_ptr->next = newnode;
        head_ptr = head_ptr->next;
    }
    cout << "--------------------------------\n";

    Node *temp;
    int target, count = 0, point = 0;
    cout << "Enter a number to  Delete all occurrences in list  : ";
    cin >> target;
    Node *ptr1;
    ptr1 = head->next;
    while (ptr1 != NULL)
    {
        if (ptr1->data == target)
        {
            break;
        }
        else
            count++;

        ptr1 = ptr1->next;
    }
    if (count > 0)
    {
        cout << "Number is not found Enter again  : ";
        cin >> target;
    }
    count = 0;
    Node *newptr;
    newptr = head->next;
    while (newptr != NULL)
    {
        temp = newptr->next;
        if (newptr->data == target && temp->data == target && point == 0)
        {
            head->next = temp;
            point++;
        }
        else if (newptr->data == target)
        {

            newptr->data = temp->data;
            newptr->next = temp->next;
            count++;
        }
        if (count == 1)
        {
            count = 0;
        }
        else
        {

            newptr = newptr->next;
        }
    }

    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    return 0;
}