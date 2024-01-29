#include <iostream>
#include <cstring>
class stack
{
private:
    char *data;
    int size;
    int TOP;

public:
    stack()
    {
        TOP = -1;
        size = 0;
    }
    void push(char value)
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
    char stacktop()
    {
        if (!isempty())
        {

            return data[TOP];
        }
        else
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
    int balance(char *exp)
    {
        size = strlen(exp);
        data = new char[size];
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(')
            {
                push('(');
            }
            else if (exp[i] == ')')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != '(')
                    {
                        return false;
                    }
                    else
                    {
                        // std::cout << "zain1\n";
                        pop();
                    }
                }
            }
            else if (exp[i] == '{')
            {
                push('{');
            }
            else if (exp[i] == '}')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != '{')
                    {
                        return false;
                    }
                    else
                    {

                        pop();
                    }
                }
            }
            else if (exp[i] == '[')
            {

                push('[');
            }
            else if (exp[i] == ']')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != '[')
                    {

                        return false;
                    }
                    else
                    {

                        pop();
                    }
                }
            }
            else
            {
            }
        }
        return isempty();
    }
};
int main()
{
    char exp[20] = "((())))";
    try
    {
        stack obj_1;
        bool num = obj_1.balance(exp);
        if (num == true)
        {
            std::cout << "Expression is balanced" << std::endl;
        }
        else
            std::cout << "Expression is Not balanced\n";
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}