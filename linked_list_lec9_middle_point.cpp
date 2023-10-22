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

    char ch;
    int middle_point, count = 0;
    Node *ptr2;
    ptr2 = head->next;

    while (ptr2 != NULL)
    {
        count++;
        ptr2 = ptr2->next;
    }

    do
    {
        middle_point = count / 2;
        if (count % 2 == 0)
        {
        }
        else
        {
            middle_point++;
        }
        Node *ptr3;
        ptr3 = head->next;

        for (int i = 2; i <= middle_point; i++)
        {
            ptr3 = ptr3->next;
        }

        Node *temp;
        temp = ptr3->next;

        Node *new_node = new Node();

        cout << "Enter a value for new middle node  : ";
        cin >> new_node->data;
        cout << "-----------------------------------\n";
        ptr3->next = new_node;
        new_node->next = temp;
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "\n-----------------------------------\n";
        cout << "You want more node in middle point\nEnter Y for Yes Or press any buttom for exit : ";
        cin >> ch;
        count++;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}