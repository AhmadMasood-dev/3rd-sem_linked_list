#include <iostream>
#include <string>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class stack
{
private:
    Node<T> *TOP;
    int size;

public:
    stack()
    {
        TOP = NULL;
        size = 0;
    }
    void push(T num)
    {
        if (TOP == NULL)
        {

            TOP = new Node<T>();
            TOP->data = num;
            TOP->next = NULL;
        }
        else
        {
            Node<T> *temp = new Node<T>();
            temp = TOP;
            TOP = new Node<T>();
            TOP->data = num;
            TOP->next = temp;
        }
        size++;
    }
    void pop()
    {
        Node<T> *temp;
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
        Node<T> *ptr = TOP;
        while (ptr != NULL)
        {
            std::cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        std::cout << "\n-----------------------------\n";
    }
    T TOP_value()
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
    void reverse()
    {
        string num;
        num = TOP->data;
        int n = num.length();
        char ch[n];
        int k = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ch[k] = num[i];
            k++;
        }
        string reverse_string;
        reverse_string = ch;
        pop();
        push(reverse_string);
    }
    ~stack() {}
};

int main()
{
    stack<string> obj_1;
    obj_1.push("w3resource");
    obj_1.Display();
    obj_1.reverse();
    obj_1.Display();
}
