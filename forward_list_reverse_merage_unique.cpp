#include <iostream>
template <class T>
struct Node
{
    int data;
    struct Node *next;
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
        front = nullptr;
        size = 0;
    }

    void push_front(const int &val)
    {
        Node<T> *temp;
        temp = new Node<T>();
        if (front == nullptr)
        {
            temp->data = val;
            temp->next = nullptr;
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
        if (front == nullptr)
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
    void unique()
    {
        Node<T> *temp;
        Node<T> *to_del;
        temp = front;

        while (temp != nullptr)
        {
            if (temp->next == nullptr)
            {
                return;
            }
            else
            {

                to_del = temp->next;
                if (to_del->data == temp->data)
                {
                    temp->next = to_del->next;
                    delete to_del;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
    void reverse()
    {
        int point = 1;
        Node<T> *temp;
        temp = front;
        Node<T> *temp_address;
        Node<T> *back_address;
        while (temp != nullptr)
        {
            temp_address = temp->next;

            if (point == 1)
            {
                temp->next = nullptr;
                back_address = temp;
                point++;
            }
            else
            {
                temp->next = back_address;
                back_address = temp;
            }

            temp = temp_address;
        }
        front = back_address;
    }
    void merge(const forward_list &rhs)
    {
        Node<T> *temp;
        temp = this->front;
        Node<T> *rhs_temp;
        rhs_temp = rhs.front;
        Node<T> *last_address_temp;
        last_address_temp = this->front;
        while (last_address_temp->next != nullptr)
        {
            last_address_temp = last_address_temp->next;
        }

        while (rhs_temp != nullptr)
        {
            last_address_temp->next = rhs_temp;
            rhs_temp = rhs_temp->next;
            last_address_temp = last_address_temp->next;
        }

        Node<T> *ptr2 = front;
        int value;
        Node<T> *i;
        Node<T> *j;
        for (i = ptr2; i->next != nullptr; i = i->next)
        {
            for (j = i->next; j != nullptr; j = j->next)
            {
                if (i->data > j->data)
                {

                    value = i->data;
                    i->data = j->data;
                    j->data = value;
                }
            }
        }
    }
    void sort()
    {
        Node<T> *temp;
        temp = front;
        Node<T> *first_temp;
        Node<T> *self_temp;
        while (temp != nullptr)
        {
            Node<T> *to_sort;
            to_sort = temp->next;
            if ()
            {
            }
        }
    }
    int Front()
    {
        if (front == nullptr)
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
        if (front == nullptr)
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
        while (ptr != nullptr)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n------------------------\n";
    }
    int size()
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
        while (front != nullptr)
        {
            pop_front();
        }
    }
};
int main()
{
    // First object
    forward_list<int> obj_1;
    obj_1.push_front(7);
    obj_1.push_front(2);
    obj_1.push_front(2);
    obj_1.push_front(5);
    obj_1.push_front(7);
    std::cout<<"First object data\n";
    obj_1.display();
    // obj_1.pop_front();
    obj_1.unique(); /// unique
    std::cout<<"First object data after unique\n";
    obj_1.display();
    obj_1.reverse(); // reverse
    std::cout<<"First object data after reverse\n";
    obj_1.display();
    // second object
    forward_list<int> obj_2;
    obj_2.push_front(1);
    obj_2.push_front(2);
    obj_2.push_front(7);
    obj_2.display();
    forward_list<int> obj_3;
    obj_3.push_front(2);
    obj_3.push_front(5);
    obj_3.display();
    obj_2.merge(obj_3); // merage
    obj_2.display();
    forward_list<int> obj_4;
    obj_4.push_front(5);
    obj_4.push_front(1);
    obj_4.push_front(9);
    obj_4.push_front(3);
    obj_4.display();
    obj_4.sort(); // starting sort
    return 0;
}
