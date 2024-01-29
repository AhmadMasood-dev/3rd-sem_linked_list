#include <iostream>
template <class T>
struct Node
{
    Node *next;
    T data;
};
template <class T>
class forward_list
{
private:
    Node<T> *front;
    int size;
  
public:
    forward_list()
    {
        front = NULL;
        size = 0;
    }
 
    void push_front(const int &val)
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (front == NULL)
        {
            temp->data = val;
            temp->next = NULL;
            front = temp;
        }
        else
        {
            temp->data = val;
            temp->next = front;
            front = temp;
        }
        size++;
    }
    void pop_front()
    {
        if (front == NULL)
        {
            throw("Stack underflow");
        }
        else
        {
            Node<T> *temp;
            temp = front->next;
            delete front;
            front = temp;
            size--;
        }
    }

    void swap(Node<T> *pre, Node<T> *node1, Node<T> *node2, Node<T> *post)
    {
        node1->next = post;
        node2->next = node1;
        pre->next = node2;
    }

    void sort()
    {
        Node<T> *temp;
        Node<T> *pre;
        Node<T> *node1;
        Node<T> *node2;
        Node<T> *post;
        Node<T> *temp2;
        pre = NULL;

        Node<T> *first = front;
        Node<T> *count_t = front;
        int count = 0;
        while (count_t != NULL)
        {
            count++;
            count_t = count_t->next;
        }
        if (count < 2)
        {
            std::cout << "List is already sorted\n";
            return;
        }

        while (first != NULL)
        {

            temp = front;
            while (temp->next != NULL)
            {
                temp2 = temp->next;

                if (temp->data > temp2->data)
                {
                    node1 = temp;
                    node2 = temp2;
                    if (front == temp)
                    {
                        pre = NULL;
                        post = temp2->next;
                        node2->next = node1;
                        node1->next = post;
                        front = node2;
                        first = node2;
                    }

                    else if (temp2->next == NULL)
                    {
                        post = NULL;
                        node1->next = NULL;
                        node2->next = node1;
                        pre->next = temp2;
                    }
                    else
                    {

                        post = temp2->next;
                        node1->next = post;
                        node2->next = node1;
                        pre->next = node2;
                    }

                    temp = temp2;
                    temp = temp->next;
                }
                else if (temp->data <= temp2->data)
                {
                    temp2 = temp;

                    temp = temp->next;
                }

                pre = temp2;
            }

            first = first->next;
        }
    }

    int Front()
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
    bool empty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    void clear()
    {
        while (!empty())
        {
            pop_front();
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
        std::cout << "\n------------------------\n";
    }
    int size_T()
    {
        if (size > 0)
        {
            return size;
        }
        else
            throw("foward list is empty");
    }
    ~forward_list()
    {
        while (front != NULL)
        {
            pop_front();
        }
    }
};

int main()
{
    // First object
    forward_list<int> obj_1;

    obj_1.push_front(9);
    std::cout << "First object data\n";
    obj_1.display();
    obj_1.sort();
    obj_1.display();

    return 0;
}