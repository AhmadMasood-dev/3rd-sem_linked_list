#include <iostream>
template <class T>
class Heap
{
private:
    T *data;
    int n;

public:
    Heap(int s = 10)
    {
        data = new T[s];
        data[0] = 0;
        n = 1;
    }
    void insert(T key)
    {
        int idx = n;
        int temp = key;
        data[n] = key;
        while (idx > 1 && temp > data[idx / 2])
        {
            data[idx] = data[idx / 2];
            idx = idx / 2;
        }
        data[idx] = temp;
        n++;
    }
    void delete_root()
    {
        int x, i, j;
        x = data[1];
        data[1] = data[n - 1];
        i = 1;
        j = i * 2;
        while (j < n - 1)
        {
            if (data[j] < data[j + 1])
            {
                j = j + 1;
            }
            if (data[i] < data[j])
            {
                int temp;
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i = j;
                j = 2 * j;
            }
            else
            {
                break;
            }
        }
        data[n - 1] = x;
        n--;
    }
    void display()
    {
        for (int i = 1; i < n; i++)
        {
            std::cout << "Data at index " << i<<" is : "  << data[i] << "\n";
        }
        std::cout << "------------------------------------------\n";
    }
};

int main()
{
    // Heap<int> obj_1;
    // obj_1.insert(35);
    // obj_1.insert(15);
    // obj_1.insert(30);
    // obj_1.insert(10);
    // obj_1.insert(25);
    // obj_1.insert(5);
    // obj_1.display();
    // obj_1.delete_root();
    // obj_1.delete_root();
    // obj_1.display();

    Heap<int> obj_2;
   int array[] = {0, 2, 7, 4, 6, 88, 56};
    obj_2.insert(2);
    obj_2.insert(3);
    obj_2.insert(4);
    obj_2.insert(5);
    obj_2.display();
    Heap<int> obj;
    for (int i = 1; i < 7; i++)
    {
        obj.insert(array[i]);
    }
    obj.display();
    return 0;
}