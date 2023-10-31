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
    int size = 5;
    char *name = new char[size];
    cout << "Enter a size how mant character in there   ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        Node *newnode = new Node();
        cin >> newnode->data;
        newnode->next = NULL;
        head_ptr->next = newnode;
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