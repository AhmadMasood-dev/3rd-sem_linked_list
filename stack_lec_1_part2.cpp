#include <iostream>
class stack
{
private:
    int *data;
    int size;
    int TOP;

public:
    stack(int s = 100)
    {
        data = new int[size];
        size = s;
        TOP = -1;
    }
    void push(int value)
    {
        if (TOP == size - 1)
        {
            throw("Size of an stack is full");
        }
        else
        {
            TOP++;
            data[TOP] = value;
        } 
    }
    void pop()
    {
        if (TOP == -1)
        {
            throw("Stack underflow");
        }
        else
        {
            TOP--;
        }
    }
    int peek(int index)
    {
        if (TOP - index + 1 < 0)
        {
            throw("Stack underflow");
        }
        return (TOP - index + 1);
    }

    int isempty()
    {
        if (TOP == -1)
        {
            return true;
        }
        return false;
    }
    int is_full()
    {
        return (TOP == size - 1);
    }
    int stacktop()
    {
        if (!isempty())
        {
            return data[TOP];
        }
        return -1;
    }
    void Display()
    {

        for (int i = TOP; i >= 0; i--)
        {
            std::cout << "The value of stack point is : " << data[i] << std::endl;
        }
        std::cout << "------------------------------------------\n";
    }
    ~stack()
    {
        delete[] data;
    }
};
int main()
{
    stack obj_1(5);
    try
    {
        obj_1.push(1);
        obj_1.push(2);
        obj_1.push(3);

        obj_1.push(4);
        obj_1.Display();
        std::cout << "The value is : " << obj_1.peek(2) << std::endl;
        std::cout << "Last element is pop form stack and now stack " << std::endl;
        obj_1.pop();
        obj_1.Display();
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}