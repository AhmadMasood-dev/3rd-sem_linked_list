#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
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
    void push(const int num)
    {
        if (TOP == NULL)
        {

            TOP = new Node();
            TOP->data = num;
            TOP->next = NULL;
        }
        else
        {
            Node *temp = new Node();
            temp = TOP;
            TOP = new Node();
            TOP->data = num;
            TOP->next = temp;
        }
        size++;
    }
    void pop()
    {
        Node *temp;
        temp = TOP->next;
        delete TOP;
        TOP = temp;
        size--;
    }
    bool isempty()
    {
        if (TOP == NULL)
            return true;
        else
            return false;
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
    int TOP_value()
    {
        if (TOP == NULL)
        {
            throw("Staack underflow");
        }
        else
        {
            return TOP->data;
        }
    }
    void del_middle()
    {
        int middle_point;
        middle_point = size / 2;
        if (!(size % 2 == 0))
        {
            middle_point++;
        }
        int array[middle_point];
        int k = 0;
        for (int i = size; i > middle_point; i--)
        {
            array[k] = TOP_value();
            pop();
            k++;
        }
        pop();
        for (int i = k - 1; i >= 0; i--)
        {
            push(array[i]);
        }
    }
    ~stack() {}
};

int main()
{
    stack obj_1;
    obj_1.push(1);
    obj_1.push(2);
    obj_1.push(3);
    obj_1.push(4);
    obj_1.push(5);
    obj_1.del_middle();
    obj_1.Display();
}
