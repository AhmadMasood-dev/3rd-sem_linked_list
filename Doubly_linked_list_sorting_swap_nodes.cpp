#include <iostream>
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
    Node<T> *head;
    int node_size;

public:
    doubly_linked_list()
    {
        node_size = 0;
        head = new Node<T>();
        head->back = head;
        head->next = head;
    }

    void push_back(const int &value)
    {
        Node<T> *temp;
        Node<T> *back_address;
        if (head->next == head)
        {
            temp = new Node<T>();
            temp->data = value;
            temp->back = head;
            temp->next = head;
            head->next = temp;
            head->back = temp;
        }
        else
        {
            back_address = head->back;
            temp = new Node<T>();
            temp->data = value;
            temp->next = head;
            head->back = temp;
            temp->back = back_address;
            back_address->next = temp;
        }

        node_size++;
    }
    void pop_back()
    {
        if (head->next == head)
        {
            throw("linked underflow");
        }
        else
        {
            Node<T> *temp;
            temp = head->back;
            temp->back->next = head;
            head->back = temp->back;
            delete temp;
            node_size--;
        }
    }

    bool empty()
    {
        if (head->next == head)
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

    void sort()
    {
        Node<T> *temp, *front, *upper_front;
        upper_front = head->next;
        Node<T> *next_temp;
        if (node_size < 2)
        {
            Display();
            throw("List is already sorted");
        }

        while (upper_front != head)
        {
            front = head->next;

            while (front->next != head)
            {
                temp = front; // first node to temp and 2 node to next_temp
                next_temp = temp->next;
                if (temp->data > next_temp->data)
                {
                    if (temp == head->next) // first 2 nodes case
                    {
                        temp->next = next_temp->next;
                        next_temp->next = temp;
                        temp->next->back = temp; // post point back
                        next_temp->back = head;
                        head->next = next_temp; // heead point to new
                        temp->back = next_temp; // first->back points to swap node
                    }
                    else if (next_temp->next == head) // last 2 node case
                    {
                        temp->next = next_temp->next;
                        next_temp->next = temp;
                        temp->next->back = temp; // post point back

                        next_temp->back = temp->back;
                        next_temp->back->next = next_temp; // pre point to new
                        temp->back = next_temp;            // first->back points to swap node
                    }
                    else // two consective nodes
                    {

                        temp->next = next_temp->next;
                        next_temp->next = temp;
                        temp->next->back = temp; // post point back
                        next_temp->back = temp->back;
                        temp->back->next = next_temp; // pre point to new
                        temp->back = next_temp;
                    }
                }
                else
                {
                    front = next_temp; // if 1 node < node 2
                }
            }
            upper_front = upper_front->next;
        }
    }
    void Display()
    {
        Node<T> *ptr;
        ptr = head->next;
        while (ptr != head)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n-----------------------------\n";
    }
};

int main()
{
    try
    {

        doubly_linked_list<int> obj_1;
        obj_1.push_back(10);
        obj_1.push_back(8);
        obj_1.push_back(4);
        obj_1.push_back(10);
        obj_1.push_back(1);
        std::cout << "Before sorted list is :   ";
        obj_1.Display();
        std::cout << "After sorting list is :   ";
        obj_1.sort();
        obj_1.Display();
        std::cout << "After last pop :   ";
        obj_1.pop_back();
        obj_1.Display();
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}