#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    struct Node *next;
};
template <class T>
class Queue
{
private:
    Node<T> *front, *back;
    int n;

public:
    Queue()
    {
        front = back = NULL;
        n = 0;
    }
    void push(int value)
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (front == NULL)
        {
            temp->data = value;
            temp->next = NULL;
            front = back = temp;
        }
        else
        {
            temp->data = value;
            temp->next = NULL;
            back->next = temp;
            back = temp;
        }
        n++;
    }
    void pop()
    {
        if (front == NULL)
        {
            // throw("Stack underflow");
        }
        else
        {
            Node<T> *temp;
            temp = front->next;
            delete front;
            front = temp;
            if (front == NULL)
            {
                back = NULL;
            }

            n--;
        }
    }
    T Front()
    {
        if (front == NULL)
        {
            throw("Stack underflow");
        }
        else
        {
            return front->data;
        }
    }
    T Back()
    {
        if (back == NULL)
        {
            throw("stack underflow");
        }
        else
        {
            return back->data;
        }
    }
    bool empty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    int size()
    {
        if (n > 0)
        {
            return n;
        }
        else
            throw("Queue is empty");
    }
    bool full()
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (temp == NULL)
        {
            return true;
        }
        else
        {
            delete temp;
            return false;
        }
    }
    void clear()
    {
        while (!empty())
        {
            pop();
        }
    }
    void display()
    {
        Node<T> *ptr = front;
        while (ptr != NULL)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n---------------------------------\n";
    }
    void delete_element()
    {
        int index;
        cout << "Enter index to delele the index-1 all elements : ";
        cin >> index;
        while (index > n)
        {
            cout << "\nInvalid index\nEnter again : ";
            cin >> index;
        }
        cout << "\nDelete the n-1 elements\n";
        for (int i = 0; i < index - 1; i++)
        {
            pop();
        }
        display();
        cout << "Now delete the nth element\n";
        pop();
    }
};
int main()
{
    Queue<int> obj_1;
    obj_1.push(1);
    obj_1.push(2);
    obj_1.push(3);
    obj_1.push(4);
    obj_1.push(5);
    obj_1.push(6);
    std::cout << "Obj data is : ";
    obj_1.display();
    obj_1.delete_element();
    obj_1.display();
    return 0;
}