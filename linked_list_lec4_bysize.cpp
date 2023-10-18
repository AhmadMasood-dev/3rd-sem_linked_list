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
    int size;
    cout << "Enter number of nodes : ";
    cin >> size;

    Node *ptr = top;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter a data of Node  " << i << " is : ";
        Node *node = new Node();
        cin >> node->data;
        node->next = NULL;
        ptr->next = node;
        ptr = ptr->next;
    }
    ptr = top->next;
    while (ptr != NULL)
    {

        cout << "DATA of Nodes is " << ptr->data << endl;
        ptr = ptr->next;
    }

    return 0;
}