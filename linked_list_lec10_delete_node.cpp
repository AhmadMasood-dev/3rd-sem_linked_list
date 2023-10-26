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
    Node *head;
    Node *first = new Node();

    head = first;
    Node *ptr1;

    ptr1 = head;
    int size;
    cout << "Enter size of nodes  ";
    cin >> size;

    while (size < 2)
    {
        cout << "invalid size\nEnter again  ";
        cin >> size;
    }

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

    Node *ptr2;
    char ch;
    int middle_point;

    cout << "Data values are : ";
    do
    {
        Node *ptr5 = head->next;
        while (ptr5 != NULL)
        {
            cout << ptr5->data << " -> ";
            ptr5 = ptr5->next;
        }
        cout << "\n--------------------------------\n";
        middle_point = size / 2;
        if (size % 2 == 0)
        {
        }
        else
        {
            middle_point++;
        }
        Node *ptr3;
        ptr3 = head->next;
        Node *temp1;
        Node *temp2;
        for (int i = 2; i <= middle_point; i++)
        {
            temp1 = ptr3->next;
            ptr3 = ptr3->next;
        }
        temp2 = ptr3->next;

        Node *ptr4 = head->next;
        int point = 1;
        while (ptr4 != NULL)
        {
            if (point == middle_point - 1)
            {
                ptr4->next = temp2;
            }
            else if (middle_point == 1)
            {
                ptr4->next = temp2->next;
            }
            else
            {
            }
            ptr4 = ptr4->next;

            point++;
        }
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "\n-----------------------------------\n";
        cout << "You want more node in middle point\nEnter Y for Yes Or press any buttom for exit : ";
        cin >> ch;
        size--;
        if (size == 1)
        {
            cout << "All middle points are deleted already\n";
            break;
        }

        cout << "\n-----------------------------------\n";
    } while (ch == 'y' || ch == 'Y');
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    delete first;
    delete ptr1;

    return 0;
}