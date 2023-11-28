#include <iostream>
using namespace std;
template <class T>
struct Node
{
    struct Node<T> *next;
    struct Node<T> *back;
    T data;
};
template <class T>
class doubly_linked_list
{
private:
    Node<T> *front;
    Node<T> *back;
    int node_size;

public:
    doubly_linked_list()
    {
        front = NULL;
        back = NULL;
        node_size = 0;
    }
    void push_front(const int &value)
    {
        Node<T> *temp;
        if (front == NULL)
        {
            temp = new Node<T>();
            temp->data = value;
            front = back = temp;
            temp->next = NULL;
            temp->back = NULL;
        }
        else
        {
            temp = new Node<T>();
            temp->data = value;
            temp->next = front;
            temp->back = NULL;
            front->back = temp;
            front = temp;
        }
        node_size++;
    }
    void push_back(const int &value)
    {
        Node<T> *temp;
        if (front == NULL)
        {
            temp = new Node<T>();
            temp->data = value;
            front = back = temp;
            temp->next = NULL;
            temp->back = NULL;
        }
        else
        {
            temp = new Node<T>();
            temp->data = value;
            temp->back = back;
            temp->back->next = temp;
            temp->next = NULL;
            back = temp;
        }
        node_size++;
    }
    void pop_back()
    {
        if (front == NULL)
        {
            throw("linked underflow");
        }
        else
        {
            Node<T> *temp;
            temp = back->back;
            delete back;
            if (front == back)
            {
                delete front;
                front = back = NULL;
            }
            else
            {
                back = temp;
                back->next = NULL;
            }
        }
        node_size--;
    }
    void pop_front()
    {
        if (front == NULL)
        {
            throw("linked underflow");
        }
        else
        {

            Node<T> *temp;
            temp = front->next;
            delete front;
            if (front == back)
            {
                delete front;
                front = back = NULL;
            }
            else
            {

                front = temp;
                front->back = NULL;
            }
        }
        node_size--;
    }
    T Front()
    {
        if (front = NULL)
        {
            throw("list underflow");
        }
        else
        {
            return front->data;
        }
    }
    T Front()
    {
        if (front = NULL)
        {
            throw("list underflow");
        }
        else
        {
            return back->data;
        }
    }
    bool empty()
    {
        if (front == NULL && back == NULL)
            return true;
        else
            return false;
    }
    bool full()
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (temp == NULL)
            return true;
        else
        {
            delete temp;
            return false;
        }
    }
    void Display()
    {
        Node<T> *ptr;
        ptr = front;
        while (ptr != NULL)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "\n-----------------------------\n";
    }
};

int main()
{
    try
    {

        doubly_linked_list<int> obj_1;
        obj_1.push_back(1);
        obj_1.push_front(10);
        obj_1.push_back(9);
        obj_1.push_front(2);
        obj_1.Display();
        obj_1.pop_back();
        obj_1.push_front(8);
        obj_1.Display();
        obj_1.pop_front();
        obj_1.Display();
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}