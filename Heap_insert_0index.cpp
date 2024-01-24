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
        n = -1;
    }
    void insert(T key)
    {
        n++;
        int idx = n;
        int temp = key;
        data[n] = key;

        while (idx > 0 && temp > data[((idx - 1) / 2)])
        {
            data[idx] = data[((idx - 1) / 2)];
            idx = (idx - 1) / 2;
        }
        data[idx] = temp;
    }
    void delete_root()
    {
        int x, i, j;
        x = data[0];
        data[0] = data[n - 1];
        i = 0;
        j = i + 1 * 2;
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
                j = 2 * j + 1;
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
        for (int i = 0; i < n; i++)
        {
            std::cout << "Data at index " << i << " is : " << data[i] << "\n";
        }
        std::cout << "------------------------------------------\n";
    }
    ~ Heap(){
        delete[] data;
    }
    
};

int main()
{

    int array[] = {2, 7, 4, 6, 88, 56};

    Heap<int> obj;
    for (int i = 0; i < 6; i++)
    {
        obj.insert(array[i]);
    }
    obj.display();
    obj.delete_root();
    obj.display();

    return 0;
}