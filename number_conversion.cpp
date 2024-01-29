#include <iostream>
#include <string>

class conversion
{
private:
    std::string number;
    int current_base;
    int target_base;

public:
    conversion(std::string num, int source, int target)
    {
        number = num;
        current_base = source;
        target_base = target;
    }
    int Decimal()
    {
        int ans = 0;
        int power = 1;
 
        for (int i = number.length() - 1; i >= 0; i--)
        {
            int digit = number[i] - '0';
            if (digit >= 10)
            {
                digit = 10 + (number[i] - 'A');
            }

            ans += digit * power;
            power *= current_base;
        }

        return ans;
    }
    std::string Base(int n)
    {
        if (n == 0)
        {
            return "0";
        }

        std::string ans = "";
        while (n != 0)
        {
            int r = n % target_base;
            if (r < 10)
            {
                ans = char('0' + r) + ans;
            }
            else
            {
                ans = char('A' + (r - 10)) + ans;
            }
            n /= target_base;
        }

        return ans;
    }
    void display()
    {
        int decno = Decimal();
        std::string final_number = Base(decno);
        std::cout << "Decimal number is: " << decno << std::endl;
        std::cout << "Number converted into base " << target_base << " is: " << final_number << std::endl;
    }
};

int main()
{
    try
    {

        std::string convert;
        int base1, Base2;

        std::cout << "Enter the base of number ( 2 , 8 , 10 , 16) : ";
        std::cin >> base1;
        std::cout << "Enter a number between 0 - " << base1 << " : ";
        std::cin >> convert;
        for (int i = 0; i < convert.length(); i++)
        {
            if (base1 == 16)
            {
                if (convert[i] > 'F')
                {
                    throw("Grater than a base number is not allowed");
                }
            }
            else if (base1 == 8)
            {
                if (convert[i] >= 8)
                {
                    throw("Grater than a base number is not allowed");
                }
            }
            else if (base1 == 10)
            {
                if (convert[i] > 10)
                {
                    throw("Grater than a base number is not allowed");
                }
            }
            else if (base1 == 2)
            {
                if (convert[i] > 1)
                {
                    throw("Grater than a base number is not allowed");
                }
            }
        }

        std::cout << "Enter the target base ( 2 , 8 , 10 , 16) : ";
        std::cin >> Base2;
        conversion obj_1(convert, base1, Base2);
        obj_1.display();
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
    return 0;
}
