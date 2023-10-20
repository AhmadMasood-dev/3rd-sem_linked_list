#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class Bubble_sort
{
private:
    int *array;
    int size;

public:
    void setvalues(int n)
    {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter a value of " << i + 1 << " is : ";
            cin >> array[i];
        }
        cout << endl;
    }
    void bubble_sort()
    {
        int temp, count;
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    count++;
                }
            }
        }
        if (count == 0)
        {
            cout << "Array is already sorted" << endl;
        }
    }
    void random_number(int n)
    {
        size = n;
        array = new int[size];
        int num;
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            num = (rand() % 10 + 1);
            array[i] = num;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "value " << i + 1 << " is : " << array[i] << endl;
        }
        cout << "----------------------------------\n";
    }
    ~Bubble_sort()
    {
        delete[] array;
    }
};

int main()
{

    int n;
    Bubble_sort obj_1, obj_2;
    cout << "Enter a size of array :  ";
    cin >> n;
    obj_1.setvalues(n);
    obj_1.bubble_sort();
    obj_2.random_number(n);
    cout << "Array of random number Before sort" << endl;
    obj_2.print();
    obj_2.bubble_sort();
    cout << "Array of random number After sort" << endl;
    obj_2.print();
    cout << "Simple Array After sort" << endl;
    obj_1.print();
    return 0;
}