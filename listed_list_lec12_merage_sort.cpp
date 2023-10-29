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
    Node *temp1;
    ptr1 = head;

    int size = 3;
    cout << "Enter size of nodes 1 ";
    // cin >> size;

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
    cout << "Enter a size for node 2  ";
    // cin >> size;
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
    Node *ptr2 = head->next;
    Node *temp2;
    for (int i = 1; i <= size * size; i++)
    {
        ptr2 = head->next;

        while (ptr2 != NULL)
        {

            temp2 = ptr2->next;
            // cout << "Temp2->data first  " << temp2->data << endl;

            if (ptr2->data > temp2->data&& temp2->data!=NULL)
            {
                int value;
                value = temp2->data;
                temp2->data = ptr2->data;
                ptr2->data = value;
            }

            if (temp2 != NULL )
            {

                ptr2 = ptr2->next;
            }
            else
            {
                break;
            }

            // cout << "Temp2->data  " << temp2->data << endl;

            Node *ptr = head->next;
            while (ptr != NULL)
            {
                cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        cout << " -> " << endl;
    }
    cout << "out";
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    delete head;

    delete ptr1;

    return 0;
}