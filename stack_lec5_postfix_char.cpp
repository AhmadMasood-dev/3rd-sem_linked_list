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
        delete[] data;
        return isempty();
    }
    void postfix(char *exp)
    {
        size = strlen(exp);
        data = new char[size];
        output = new char[size];
        std::cout << "Expression is : " << exp << std::endl;
        int k = 0;
        for (int i = 0; exp[i] != '\0'; i++)
        {

            if (exp[i] - '0' >= 0 && exp[i] - '0' <= 9)
            {
                output[k] = exp[i];
                k++;
            }
            else if (exp[i] == '+' || exp[i] == '/' || exp[i] == '*' || exp[i] == '-')
            {
                if (isempty())
                {
                    std::cout << data << "data\n";
                    push(exp[i]);
                }
                else if (exp[i] >= stacktop())
                {
                    std::cout << data << "data2\n";
                    push(exp[i]);
                }
                else if (exp[i] <= stacktop())
                {
                    while (exp[i] <= stacktop())
                    {
                        // Display();
                        std::cout << data << "Pop is " << stacktop() << std::endl;
                        output[k] = stacktop();
                        k++;
                        pop();
                    }
                    push(exp[i]);
                }
            }
        }
        std::cout << "data is : " << data << " output " << output << std::endl;
        while (TOP != -1)
        {
            std::cout << "Pop is " << stacktop();
            output[k] = stacktop();
            k++;
            pop();
        }

        std::cout << "data is : " << data << " output " << output << std::endl;
        clear();
        delete[] data;
        // for (int i = 0; output[i] != '\0'; i++)
        // {
        //     if (output[i] == '+' || output[i] == '-' || output[i] == '*' || output[i] == '/')
        //     {
        //         char option;
        //         option = output[i];
        //         switch (option)
        //         {
        //         case '+':
        //         {
        //             if (i==2)
        //             {
        //                 push(output[i-2]+output[i-1]);
        //             }

        //         }

        //         break;

        //         default:
        //             break;
        //         }
        //     }
        // }
        // Evaluate postfix expression
        data = new char[5];
        std::cout << "top is " << TOP;
        for (int i = 0; output[i] != '\0'; i++)
        {

            if (output[i] - '0' >= 0 && output[i] - '0' <= 9)
            {
                push(output[i]);
            }
            else if (output[i] == '+' || output[i] == '-' || output[i] == '*' || output[i] == '/')
            {
                int operand2 = stacktop() - '0';
                pop();
                int operand1 = stacktop() - '0';
                pop();

                switch (output[i])
                {
                case '+':
                    push(operand1 + operand2 + '0');
                    break;
                case '-':
                    push(operand1 - operand2 + '0');
                    break;
                case '*':
                    push(operand1 * operand2 + '0');
                    break;
                case '/':
                    push(operand1 / operand2 + '0');
                    break;
                }
            }
            std::cout << "\nTop is : " << TOP << "stack is : " << stacktop() << "\n";
        }
    }
    void Result()
    {
        if (isempty())
        {
            std::cout << "Result: Stack is empty" << std::endl;
        }
        else
        {
            std::cout << "Result: " << stacktop() << std::endl;
        }
        Display();
    }
};
int main()
{
    // char exp[20] = " 8/9-2+8-7/6*5";
    char exp[20] = " 2+2*8/4 ";
    try
    {
        stack obj_1;
        bool num = obj_1.balance(exp);
        if (num == true)
        {
            std::cout << "Expression is balanced hello" << std::endl;
        }
        else
            std::cout << "Expression is Not balanced\n";
        obj_1.postfix(exp);
        obj_1.Display();
        obj_1.Result();
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    return 0;
}