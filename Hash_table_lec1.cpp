#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class myHash_table
{
private:
    Node<T> *data;
    int size;

    int hash(int val)
    {
        return val % 10;
    }

    void sorted_insert(Node<T> *hashing, int key)
    {
        Node<T> *temp, *q;
        temp = hashing;

        Node<T> *new_node = new Node<T>;
        new_node->data = key;
        new_node->next = NULL;

        if (temp->next == NULL)
        {
            temp->next = new_node;
        }
        else
        {
            q = temp->next;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = new_node;
        }
    }

public:
    myHash_table(int tableSize = 10)
    {
        size = tableSize;
        data = new Node<T>[size];
        for (int i = 0; i < size; i++)
        {
            data[i].next = NULL;
        }
    }

    void insert(int val)
    {
        int idx = hash(val);
        sorted_insert(&data[idx], val);
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            Node<T> *ptr = data[i].next; 
            while (ptr != NULL)
            {
                cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    myHash_table<int> obj_1;
    obj_1.insert(14);
    obj_1.insert(24);
    obj_1.display();
    cout << "zain" << endl;
    return 0;
}
