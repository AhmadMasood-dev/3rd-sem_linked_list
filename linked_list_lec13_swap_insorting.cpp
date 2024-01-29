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
    Node *pre = head;
    head_ptr = head->next;
    while (head_ptr != NULL)
    {
        first = head->next; // 7
        while (first != NULL)
        {
            temp = first;        // 7
            temp2 = first->next; // 4
            cout << "temp->data" << temp->data << "temp2->data" << temp2->data << "pre->data" << pre->data << "\n";
            if (temp->data > temp2->data)
            {
                // if (point == 1)
                //{

                Node *p1, *p2;
                p2 = temp2->next;   // 2
                p1 = temp->next;    // 4
                temp2->next = temp; // 10
                temp->next = p2;    // 2
                if (head->next == temp)
                {
                    head->next = temp2;
                    first = head->next;
                    cout << "change head";
                }
                else if (temp->next == NULL)
                {
                    pre->next = temp2;
                }
                else
                {
                    cout << "first->data " << first->data << "\n"
                         << "pre->data" << pre->data << "\n";

                    first = p1;
                    pre->next = first;
                }

                // }
            }

            pre = first;
            first = first->next;
        }
        head_ptr = head_ptr->next;
    }

    Node *ptr = head->next;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    return 0;
}