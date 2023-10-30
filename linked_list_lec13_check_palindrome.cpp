#include <iostream>
using namespace std;
class Node
{
public:
    char letter;
    Node *next;
};
int main()
{
    Node *head = new Node();
    Node *head_ptr;
    head_ptr = head;
    int size = 5;
    char *name = new char[size];
    cout<<"Enter a size how mant character in there   ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        Node *newnode = new Node();
        cin >> newnode->letter;
        newnode->next = NULL;
        head_ptr->next = newnode;
        name[i] = newnode->letter;
        head_ptr = head_ptr->next;
    }
    cout << "--------------------------------\n";
    int point = 1;
    Node *newptr;
    newptr = head->next;
    Node *temp;
    Node *temp2;
    char *name2 = new char[size];
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
    Node *ptr5 = temp2;
    int i = 0;
    Node *ptr = temp2;
    while (ptr != NULL)
    {
        name2[i] = ptr->letter;
        cout << ptr->letter << " -> ";
        ptr = ptr->next;
        i++;
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (name[i] == name2[i]){ }       
    }
    if (count == size)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}