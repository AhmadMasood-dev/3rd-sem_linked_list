#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class Insertion_sort
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
    void insertion_sort()
    {
        int key = 0, temp = 0;
        for (int i = 1; i <= size - 1; i++)
        {
            key = array[i];
            temp = i - 1;

            while (array[temp] > key && temp >= 0)
            {
                array[temp + 1] = array[temp];
                temp--;
            }
            array[temp + 1] = key;
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
    ~Insertion_sort()
    {
        delete[] array;
    }
};

int main()
{

    Insertion_sort obj_1, obj_2;
    int n;
    cout << "Enter a size of array :  ";
    cin >> n;
    obj_1.setvalues(n);
    obj_1.insertion_sort();
    obj_2.random_number(n);

    cout << "Array of random number Before sort" << endl;

    obj_2.print();
    obj_2.insertion_sort();

    cout << "Array of random number After sort" << endl;

    obj_2.print();
    cout << "Simple Array is" << endl;

    obj_1.print();
    return 0;
}