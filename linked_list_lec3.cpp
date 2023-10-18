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
    Node *top;
    int size;
    cout << "Enter number of nodes : ";
    cin >> size;
    Node *first = new Node();
    top = first;

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter a data of Node  " << i << " is : ";
        Node *node = new Node();
        cin >> node->data;
        node->next = NULL;
        top->next = node;
        top = top->next;
    }
    Node *ptr;
    ptr = first->next;
    while (ptr != NULL)
    {

        cout << "DATA of Nodes is " << ptr->data << endl;
        ptr = ptr->next;
    }

    return 0;
}