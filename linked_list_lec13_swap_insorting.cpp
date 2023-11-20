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

    int size = 4;
    cout << "Enter size of nodes 1 ";
    // cin >> size;

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
    Node *first;
    first = head->next;
    int point = 1;
    Node *temp, *temp2;

    while (first != NULL)
    {

        temp = first;
        while (temp != NULL)
        {
            temp2 = temp->next;
            if (temp->data > temp2->data )
            {
                cout << "if";
            temp = temp->next;
            }
            else
            {
                Node *newnode;
                newnode = temp2->next;
                temp2->next = temp;
                temp->next = newnode;
            }
        }
        first = first->next;
    }

    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    return 0;
}