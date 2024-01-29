#include <iostream>
using namespace std;
class Node
{

public:
    int data1;
    int data2;
    Node *next_ptr;
    Node()
    {
        cout << "constructor invoke : " << endl;
        data1 = 1;
    }
}; 
void print(Node *n)
{
    while (n != NULL)
    {
        cout << "data 1 is : " << n->data1 << endl;
        n = n->next_ptr;
    }
}
int main()
{
    Node *first = new Node;
    Node *second = new Node;
    Node *five = new Node;

    first->next_ptr = second;
    second->next_ptr = five;
    five->next_ptr = NULL;

    print(first);

    delete five;
    delete first;
    delete second;
    return 0;
}