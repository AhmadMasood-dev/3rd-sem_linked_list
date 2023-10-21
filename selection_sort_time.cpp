#include <iostream>
#include <chrono>
#include <thread>
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
            array[i] = i + i + 1;
        }
        std::cout << std::endl;
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
        cout << "value are : ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << "   ";
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

    selection_sort obj_1, obj_2;
    int n = 4;

    obj_1.setvalues(n);
    std::cout << "Simple Array is:" << std::endl;
    obj_1.print();

    auto start = std::chrono::steady_clock::now();
    obj_1.selection_Sort();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    float ms = elapsed_seconds.count() * 1000;
    std::cout << "Sorting took " << ms << " ms" << std::endl;

    obj_2.random_number(n);

    std::cout << "Array of random numbers before sort:" << std::endl;
    obj_2.print();

    start = std::chrono::steady_clock::now();

    obj_2.selection_Sort();
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;

    ms = elapsed_seconds.count() * 1000;

    std::cout << "Array of random numbers after sort:" << std::endl;
    obj_2.print();

    std::cout << "Sorting took " << ms << " ms" << std::endl;

    return 0;
}
