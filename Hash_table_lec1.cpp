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

    void insert(T val)
    {
        int idx = hash(val);
        sorted_insert(&data[idx], val);
    }
    bool find(T key)
    {
        int idx = hash(key);
        Node<T> *temp = data[idx].next;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                std::cout<<temp->data;
                return true;
            }
            temp = temp->next;
        }
        return false;
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
    obj_1.insert(34);
    obj_1.insert(24);
    obj_1.insert(22);
    obj_1.insert(23);
    obj_1.insert(12);
    obj_1.insert(25);
    obj_1.insert(19);
    bool op = obj_1.find(34);
    if (op == 1)
    {
        std::cout << "  Data Fount successfully\n";
    }
    else
    {
    std:;
        cout << "Data not found\n";
    }
    std::cout << "-------------------------------\n";
    obj_1.display();
    cout << "zain" << endl;
    return 0;
}
