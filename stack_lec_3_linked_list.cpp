#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};
class stack
{
private:
    Node *TOP;
    int size;

public:
    stack()
    {
        TOP = NULL;
        size = 0;
    }
    stack(const Node &rhs)
    {
        this->size = size;
        Node *array = new Node[size];
        for (int i = size; i >= 1; i--)
        {
            Node *new_node = new Node();
            TOP = new Node();
            Node *temp;
            temp = new_node;
            new_node->data = array[i].data;
            new_node->next = array[i].next;
            TOP = temp;
        }
    }
    Node &operator=(const Node &rhs)
    {

        this->size = size;
        Node *array = new Node[size];
        for (int i = size; i >= 1; i--)
        {
            Node *new_node = new Node();
            TOP = new Node();
            Node *temp;
            temp = new_node;
            new_node->data = array[i].data;
            new_node->next = array[i].next;
            TOP = temp;
        }
    }
    void push(const int &val)
    {
        size++;

        if (TOP == NULL)
        {
            TOP = new Node();
            TOP->data = val;
            TOP->next = NULL;
        }
        else
        {
            Node *temp;
            temp = TOP;
            TOP = new Node();
            TOP->data = val;
            TOP->next = temp;
        }
    }
    void pop()
    {
        Node *temp2 = TOP->next; // to-do
        delete TOP;
        TOP = temp2;
        size--;
    }
    int TOP_Func()
    {
        return TOP->data;
    }

    bool empty()
    {
        if (TOP == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int total_size()
    {
        return size;
    }
    bool full()
    {
        Node *temp = new Node();
        if (temp != NULL)
        {
            delete temp;
            return false;
        }
        else
        {
            return true;
        }
    }

    void Display()
    {
        Node *ptr = TOP;
        while (ptr != NULL)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n-----------------------------\n";
    }
    ~stack()
    {
    }
};
int main()
{
    stack obj_1;
    obj_1.push(1);
    obj_1.push(2);
    obj_1.push(3);
    // std::cout << obj_1.TOP_Func() << std::endl;
    //  std::cout << obj_1.total_size();

    std::cout << "Values of object 1 in stacks are :  ";
    obj_1.Display();
    std::cout << "Values object 1 in stacks After pop() :  ";
    obj_1.pop();
    obj_1.Display();
    stack obj_2 = obj_1;
    std::cout << "Values of object 1 in stacks by doing copy constructor :  ";
    obj_2.Display();
    std::cout << "Values of object 2 in stacks are :  ";
    obj_2.push(6);
    obj_2.push(7);
    obj_2.Display();
    std::cout << "Values object 2 in stacks After pop() :  ";
    obj_2.pop();
    obj_2.Display();
    return 0;
}
