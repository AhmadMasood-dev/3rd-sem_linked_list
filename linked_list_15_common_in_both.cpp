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
    cout << "Enter number of nodes for second list : ";
    cin >> size;
    Node *Second_head = new Node();
    Node *Second_ptr;
    Second_ptr = Second_head;
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter a data of Node  " << i << " is : ";
        Node *newnode = new Node();
        cin >> newnode->data;
        newnode->next = NULL;
        Second_ptr->next = newnode;
        Second_ptr = Second_ptr->next;
    }
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "\n";
    ptr = Second_head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "\n";
    Node *temp = new Node();
    Node *temp_ptr;
    temp_ptr = temp;
    Node *top_ptr = head->next;
    Node *ptr2;
    int count = 0;
    while (top_ptr != NULL)
    {
        ptr2 = Second_head->next;
        while (ptr2 != NULL)
        {
            if (top_ptr->data == ptr2->data)
            {
                Node *newnode = new Node();
                newnode->data = ptr2->data;
                newnode->next = NULL;
                temp_ptr->next = newnode;
                temp_ptr = temp_ptr->next;
                count++;
            }
            ptr2 = ptr2->next;
        }
        top_ptr = top_ptr->next;
    }
    if (count > 0)
    {
        cout << "----  Common numbers are  -----\n";

        ptr = temp->next;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "Common numbers does not exist " << endl;
    }

    return 0;
}