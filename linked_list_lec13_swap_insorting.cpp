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

    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }



    return 0;
}