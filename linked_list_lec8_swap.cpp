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

    Node *one = new Node;
    Node *two = new Node;
    Node *three = new Node;
    Node *four = new Node;
    Node *five = new Node;
    Node *six = new Node;

    one->data = 1;
    one->next = two;
    two->data = 2;
    two->next = three;
    three->data = 3;
    three->next = four;
    four->data = 4;
    four->next = five;
    five->data = 5;
    five->next = six;
    six->data = 6;
    six->next = NULL;

    head = one;
    int location1, location2;
    cout << "Enter nodes to swap \nswap 1 number is : ";
    cin >> location1;
    cout << "swap 2 number is : ";
    cin >> location2;
    if (location1 == location2)
    {
        cout << "Invalid swap \nEnter again";
        cin >> location2;
    }

    int point = 1;
    Node *newptr, *p1, *p2;
    newptr = head;
    Node *temp1 = new Node();
    Node *temp2 = new Node();

    while (newptr != NULL)
    {

        if (point == location1)
        {
            temp1 = newptr;
        }
        else if (point == location2)
        {

            temp2 = newptr;
        }
        else
        {
        }

        newptr = newptr->next;
        point++;
    }

    point = 1;
    p1 = temp1->next;
    p2 = temp2->next;

    Node *p = head;
    while (p != NULL)
    {

        if (point == location1 - 1)
        {

            p->next = temp2;
            temp2->next = p1;
        }

        else if (point == location2 - 1)
        {

            p->next = temp1;
            temp1->next = p2;
        }
        else if (location1 == 1)
        {
            Node *newnode = new Node();
            newnode->next = temp2;
            if (location2 == 2)
            {
                temp2->next = temp1;
            }
            else
            {

                temp2->next = p1;
            }
            head = newnode;
        }
        else
        {
        }

        point++;
        p = p->next;
    }
    Node *ptr;
    if (location1 == 1)
    {

        ptr = head->next;
    }
    else
    {
        ptr = head;
    }
    cout << "Data of List after swap is :   ";
    while (ptr != NULL)
    {
        cout << ptr->data << " -> " << endl;
        ptr = ptr->next;
    }

    return 0;
}
