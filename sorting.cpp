#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>

class Sorting
{
private:
    int *array;
    int size;
    static int count;

public:
    void setvalues(int n)
    {
        size = n;
        array = new int[size];
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

            return;
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
    void take_time(std::fstream &file, int choice)
    {
        if (!file.is_open())
        {
            std::cout << "File is not open\n";
        }
        else
        {
            Sorting::count++;
            int runs = 10;
            double total_time = 0.0;
            std::string name;
            for (int i = 1; i <= runs; i++)
            {

                if (choice == 1)
                {
                    name = "Selection_sort";

                    auto start = std::chrono::steady_clock::now();
                    selection_Sort();
                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    total_time += elapsed_seconds.count();
                    // std::cout << "Time is " << elapsed_seconds.count() << std::endl;
                }
                else if (choice == 2)
                {
                    name = "Bubble_sort";

                    auto start = std::chrono::steady_clock::now();
                    bubble_sort();
                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    total_time += elapsed_seconds.count();
                    // std::cout << "Time is " << elapsed_seconds.count() << std::endl;
                }
                else if (choice == 3)
                {
                    name = "Insertion_sort";

                    auto start = std::chrono::steady_clock::now();
                    insertion_sort();
                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end - start;
                    total_time += elapsed_seconds.count();
                    // std::cout << "Time is " << elapsed_seconds.count() << std::endl;
                }
            }
            double average = total_time / runs;
            if (count == 1)
            {
                file << name << "," << size << ","
                     << "Sorted"
                     << "," << runs << "," << average << "\n";
                std::cout << "Data store successfully of sorted array\n";
            }
            if (count == 2)
            {

                file << name << "," << size << ","
                     << "Random"
                     << "," << runs << "," << average << "\n";
                std::cout << "Data store successfully of Random array\n";
            }
            else
            {
                count = 0;
            }

            std::cout << "Data store successfully\n";
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
int Sorting::count = 0;

int main()
{
    Sorting obj_1, obj_2;
    int n = 100000;
    obj_1.setvalues(n);

    int option, choice;
    char file_name[20] = "Sorting.csv";
    std::fstream file(file_name, std::ios::out);
    file << "Algorithm,Array Size,Array Type,Number of Runs,Average Time (s)\n";
    file.close();

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
            file.open("Sorting.csv");
            obj_1.take_time(file, 1);
            obj_2.random_number(n);
            obj_2.take_time(file, 1);
            file.close();
        }
        break;
        case 2:
        {
            std::cout << "Takes some Time..\n";
            file.open("Sorting.csv");
            obj_1.take_time(file, 2);
            obj_2.random_number(n);
            obj_2.take_time(file, 2);
            file.close();
        }
        break;
        case 3:
        {
            std::cout << "Takes some Time..\n";
            file.open("Sorting.csv");
            obj_1.take_time(file, 2);
            obj_2.random_number(n);
            obj_2.take_time(file, 2);
            file.close();
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
