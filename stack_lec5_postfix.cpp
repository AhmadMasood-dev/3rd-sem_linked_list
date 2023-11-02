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

public:
    stack()
    {
        TOP = NULL;
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
    }
    void pop()
    {
        Node *temp;
        temp = TOP->next;
        delete TOP;
        TOP = temp;
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
    ~stack() {}
};

int main()
{
    stack obj_1;
    obj_1.push(1);
    cout << "TOP value is " << obj_1.TOP_value() << endl;
    obj_1.Display();
}
