#include <iostream>
#include <chrono>
#include <thread>
template <class T>
class Sorting
{
private:
    T *array;
    int size;

public:
    void setvalues(int n)
    {
        size = n;
        array = new T[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = i + 1;
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
            std::cout << "Array is already sorted\n";
        }
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
                std::cout << "Array is sorted\n";
                return;
            }
        }
    }

    void insertion_sort()
    {
        int key = 0, temp = 0, count;
        for (int i = 1; i <= size - 1; i++)
        {
            key = array[i];
            temp = i - 1;

            while (array[temp] > key && temp >= 0)
            {
                array[temp + 1] = array[temp];
                temp--;
                count++;
            }
            array[temp + 1] = key;
        }
        if (count == 0)
        {
            std::cout << "Array is already sorted\n";
            return;
        }
    }
    void random_number(int n)
    {
        size = n;
        array = new T[size];
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
        std::cout << "value are : ";
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << "   ";
        }
        std::cout << "----------------------------------\n";
    }
    ~Sorting()
    {

        delete[] array;
    }
};

int main()
{
    Sorting<int> obj_1, obj_2;
    int n = 100000;
    obj_1.setvalues(n);

    int option, choice;

    do
    {
        std::cout << "1. Selection sort\n";
        std::cout << "2. Bubble sort\n";
        std::cout << "3. Insertion sort\n";
        std::cout << "4. Exit..\n";
        std::cout << "Enter option\n";
        std::cin >> option;
        switch (option)
        {
        case 1:
        {
            std::cout << "Takes some Time..\n";
            auto start = std::chrono::steady_clock::now();

            obj_1.selection_Sort();

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "Already sorted array took " << elapsed_seconds.count() << " s " << std::endl;

            obj_2.random_number(n);
            start = std::chrono::steady_clock::now();
            obj_2.selection_Sort();
            end = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Random Array after sorting takes : " << elapsed_seconds.count() << " s " << std::endl;
        }
        break;
        case 2:
        {
            std::cout << "Takes some Time..\n";
            auto start = std::chrono::steady_clock::now();

            obj_1.bubble_sort();

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "Already sorted array took " << elapsed_seconds.count() << " s " << std::endl;

            obj_2.random_number(n);
            start = std::chrono::steady_clock::now();
            obj_2.bubble_sort();
            end = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Random Array after sorting takes : " << elapsed_seconds.count() << " s " << std::endl;
        }
        break;
        case 3:
        {
            std::cout << "Takes some Time..\n";
            auto start = std::chrono::steady_clock::now();

            obj_1.insertion_sort();

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "Already sorted array took " << elapsed_seconds.count() << " s " << std::endl;

            obj_2.random_number(n);
            start = std::chrono::steady_clock::now();
            obj_2.insertion_sort();
            end = std::chrono::steady_clock::now();
            elapsed_seconds = end - start;
            std::cout << "Random Array after sorting takes : " << elapsed_seconds.count() << " s " << std::endl;
        }
        break;
        case 4:
        {
            std::cout << "Exiting the Program...\n";
        }
        break;
        default:
            std::cout << "Invalid option\n";
            break;
        }
    } while (option != 4);
    return 0;
}
