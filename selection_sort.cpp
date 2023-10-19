#include <iostream>
using namespace std;
class selection_sort
{
private:
    int *array;
    int size;

public:
    selection_sort()
    {
    }
    ~selection_sort()
    {
        delete[] array;
    }
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
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Value "<<i+1<<" is : " << array[i] << endl;
        }
        cout << "----------------------------------\n";
    }
    void bubblesort()
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
            throw("array is already sorted");
        }
    }
};
int main()
{
    int n;
    selection_sort obj_1;
    cout << "Enter a size of array :  ";
    cin >> n;
    try
    {
        obj_1.setvalues(n);
        obj_1.bubblesort();
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    obj_1.print();
    return 0;
}
