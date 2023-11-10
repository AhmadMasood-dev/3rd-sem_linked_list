#include <iostream>
#include <cstring>
class stack
{
private:
    char *data;
    int size;
    char *output;
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
    void clear()
    {
        while (TOP != -1)
        {
            pop();
        }
    }
    int balance(char *exp)
    {
        size = strlen(exp);
        data = new char[size];
        data = exp;
        for (int i = 0; data[i] != '\0'; i++)
        {
            if (data[i] == '(')
            {
                push('(');
            }
            else if (data[i] == ')')
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
                        pop();
                    }
                }
            }
            else if (data[i] == '{')
            {
                push('{');
            }
            else if (data[i] == '}')
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
            else if (data[i] == '[')
            {

                push('[');
            }
            else if (data[i] == ']')
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
        clear();
        return isempty();
    }
    void postfix(char *exp)
    {
        size = strlen(exp);
        data = new char[size];
        data = exp;
        std::cout << "data is:\n"
                  << data;
        int k = 0;
        for (int i = 0; data[i] != '\0'; i++)
        {
            if (data[i] >= 0 && data[i] <= 9)
            {
                data[k] = data[i];
                k++;
            }
            else if (data[i] >= '+' && data[i] <= '/')
            {

                if (isempty())
                {
                    push(data[i]);
                }
            }
        }
    }
};
int main()
{
    char exp[20] = "([{(a+b)*(c+d)}])";
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
        obj_1.postfix(exp);
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}