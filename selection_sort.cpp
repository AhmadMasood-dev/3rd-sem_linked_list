#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class selection_sort
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

    void selection_Sort()
    {
        int min_index, temp, count = 0;
        for (int i = 0; i < size - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[min_index])
                {
                    min_index = j;
                    count++;
                }
            }
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
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
            cout << "Value " << i + 1 << " is : " << array[i] << endl;
        }
        cout << "----------------------------------\n";
    }
    ~selection_sort()
    {
        delete[] array;
    }
};
int main()
{
    int n;
    selection_sort obj_1, obj_2;
    cout << "Enter a size of array :  ";
    cin >> n;

    obj_1.setvalues(n);
    obj_1.selection_Sort();
    obj_2.random_number(n);
    cout << "Array of random number Before sort" << endl;
    obj_2.print();
    obj_2.selection_Sort();
    cout << "Array of random number After sort" << endl;
    obj_2.print();
    cout << "Simple Array After sort" << endl;
    obj_1.print();
    return 0;
}
