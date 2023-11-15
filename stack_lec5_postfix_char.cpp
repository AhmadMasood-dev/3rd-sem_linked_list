#include <iostream>
#include <cstring>
#include <string>
class stack
{
private:
    std::string *data;
    int size;
    std::string *output;
    int TOP;

public:
    stack()
    {
        TOP = -1;
        size = 0;
        data = new std::string[10];
    }
    void push(std::string value)
    {
        if (TOP == size - 1)
        {
            throw("Size of an stack is full");
        }
        else
        {
            TOP++;
            data[TOP] = value;
            // std::cout << "TOP value in pus is " << data[TOP] << "\n";
        }
    }
    void pop()
    {
        // std::cout << "POPOP";
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
    std::string stacktop()
    {
        if (!isempty())
        {

            return data[TOP];
        }
        else
            return 0;
    }
    void Display()
    {

        for (int i = TOP - 1; i >= 0; i--)
        {
            std::cout << "The value of stack point is : " << data[i] << std::endl;
        }
        std::cout << "\n------------------------------------------\n";
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
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(')
            {
                push("(");
            }
            else if (exp[i] == ')')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != "(")
                    {
                        return false;
                    }
                    else
                    {
                        pop();
                    }
                }
            }
            else if (exp[i] == '{')
            {
                push("{");
            }
            else if (exp[i] == '}')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != "{")
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

                push("[");
            }
            else if (exp[i] == ']')
            {
                if (isempty() == true)
                {
                    return false;
                }
                else
                {
                    if (stacktop() != "[")
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
    void postfix(std::string exp)
    {

        size = exp.length();
        output = new std::string[size];
        std::cout << "Expression is : " << exp << std::endl;
        int k = 0;
        std::string exp_convert;
        for (int i = 0; exp[i] != '\0'; i++)
        {

            if (exp[i] - '0' >= 0 && exp[i] - '0' <= 9)
            {
                exp_convert = exp[i];
                output[k] = exp_convert;
                k++;
            }
            else if (exp[i] == '+' || exp[i] == '/' || exp[i] == '*' || exp[i] == '-')
            {
                exp_convert = exp[i];
                if (isempty())
                {
                    exp_convert = exp[i];
                    // std::cout << "exp_cnver 1" << exp_convert << "\n";
                    push(exp_convert);
                }
                else if (exp_convert >= stacktop())
                {
                    exp_convert = exp[i];
                    // std::cout << "exp_cnver 2" << exp_convert << stacktop() << "\n";
                    push(exp_convert);
                }
                else if (exp_convert <= stacktop())
                {
                    while (exp_convert <= stacktop())
                    {
                        // Display();
                        // std::cout << "Pop is : " << stacktop() << std::endl;
                        exp_convert = stacktop();
                        output[k] = exp_convert;
                        k++;
                        pop();
                        // std::cout << "new pus is : " << stacktop() << std::endl;
                    }
                    exp_convert = exp[i];
                    push(exp_convert);
                }
            }
        }
        //  std::cout << "data is : " << data << " output " << output << std::endl;
        while (TOP != -1)
        {
            //  std::cout << "Pop operator is " << stacktop();
            output[k] = stacktop();
            k++;
            pop();
        }

        // std::cout << "data is : " << data << " output " << output << std::endl;

        for (int i = 0; output[i] != "\0"; i++)
        {
            if (output[i] >= "0" && output[i] <= "9")
            {
                push(output[i]); // Convert to string and push onto the stack
            }
            else if (output[i] == "+")
            {
                std::string num2 = stacktop();
                pop();
                std::string num1 = stacktop();
                pop();
                push(std::to_string(std::stoi(num1) + std::stoi(num2)));
            }
            else if (output[i] == "-")
            {
                std::string num2 = stacktop();
                pop();
                std::string num1 = stacktop();
                pop();
                push(std::to_string(std::stoi(num1) - std::stoi(num2)));
            }
            else if (output[i] == "*")
            {
                std::string num2 = stacktop();
                pop();
                std::string num1 = stacktop();
                pop();
                push(std::to_string(std::stoi(num1) * std::stoi(num2)));
            }
            else if (output[i] == "/")
            {
                std::string num2 = stacktop();
                pop();
                std::string num1 = stacktop();
                pop();
                push(std::to_string(std::stoi(num1) / std::stoi(num2)));
            }
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
        // Display();
    }
};
int main()
{
    std::cout << "Enter a simple expression ";
    char exp[20];
    std::cin >> exp;

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