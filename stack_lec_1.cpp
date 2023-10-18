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
        TOP = 0;
    }
    stack(const stack &rhs)
    {
        data = new int[rhs.size];
        this->data = rhs.data;
        this->size = rhs.size;
        this->TOP = rhs.TOP;
    }
    void push(int value)
    {
        if (TOP == size - 1)
        {
            throw("Size of an stack is full");
        }
        else
        {
            data[TOP] = value;
            TOP++;
        }
    }
    void pop()
    {
        if (TOP == 0)
        {
            throw("Stack is Empty");
        }
        else
        {
            TOP--;
        }
    }
    int top_fun() const
    {
        if (TOP == 0)
        {
            throw("Stack is empty");
        }
        else
        {

            return data[TOP - 1];
        }
    }
    int size_func() const
    {
        return TOP;
    }
    bool empty() const
    {
        if (TOP == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void full() const
    {

        if (TOP == size - 1)
        {
            throw("Stack is full NOW");
        }
        else
        {
            std::cout << size << " and array have a space of " << size - TOP << " points" << std::endl;
        }
    }
    stack &operator=(const stack &rhs)
    {
        if (this->data == rhs.data)
        {

            return *this;
        }
        else if (this->size != rhs.size)
        {
            delete[] this->data;
            data = new int[rhs.size];
        }
        this->data = rhs.data;
        this->size = rhs.size;
        this->TOP = rhs.TOP;
    }

    void Display()
    {
        std::cout << "The data of stack" << std::endl;
        for (int i = 0; i < TOP; i++)
        {
            std::cout << "The value of stack point " << i + 1 << " is : " << data[i] << std::endl;
        }
    }
    ~stack()
    {
        delete[] data;
    }
};

int main()
{
    try
    {
        stack obj_1(7); //Object with size as parameter
        obj_1.push(1);  //store first value
        int empty_func = obj_1.empty(); //check empty function
        if (empty_func == true)
        {
            std::cout << "Now Stack is empty" << std::endl;
        }
        else
        {
            obj_1.push(2);
            obj_1.push(3);
            obj_1.push(4);
            obj_1.push(5);  //store values

            std::cout << "The current size of stack is : " << obj_1.size_func() << std::endl; //current size of stack
            std::cout << "The TOP value is " << obj_1.top_fun() << std::endl;  //TOP value of stack
            std::cout << "The full size of stack is : ";
            obj_1.full(); //Max size of array and stored value in stack

            std::cout << "The store data in obj_1 are " << std::endl;
            obj_1.Display(); 

            obj_1.pop(); //remove last element form stack

            std::cout << "\nRemoveing last element form stack and now TOP value is : " << obj_1.top_fun() << std::endl;
            obj_1.Display();

            stack obj_2 = obj_1; //copy constructor

            std::cout << "New object is created and assigned form object 1" << std::endl;
            obj_2.Display();

            stack obj_3;
            obj_3 = obj_1;  //operator=

            std::cout << "New object is created and assigned form object 1" << std::endl;
            obj_3.Display();

            std::cout << std::endl;
        }
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}