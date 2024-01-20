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
        n = 0;
    }
    void insert(T key)
    {
        int idx = n;
        int temp = key;
        data[n] = key;
        n++;
        while (idx > 0 && temp > data[idx / 2])
        {
            data[idx] = data[idx / 2];
            idx = idx / 2; /* code */
        }
        data[idx] = temp;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "DAta is : " << data[i] << "  at index " << i + 1 << "\n";
        }
    }
};

int main()
{
    Heap<int> obj_1;
    obj_1.insert(10);
    obj_1.insert(20);
    obj_1.insert(30);
    obj_1.insert(25);
    obj_1.insert(5);
    obj_1.insert(40);
    obj_1.display();
    return 0;
}