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
        int temp;
        bool iteration = false;
        for (int i = 1; i < size; i++)
        {
            iteration = true;

            for (int j = 0; j < size - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    iteration = false;
                }
            }
            if (iteration == true)
            {
                cout << "Array is sorted " << endl;
                return;
            }
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
         cout << "value are : ";
        for (int i = 0; i < size; i++)
        {
           cout << array[i] <<"   ";
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

    Bubble_sort obj_1, obj_2;
    int n;
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
    cout << "Simple Array is" << endl;

    obj_1.print();
    return 0;
}