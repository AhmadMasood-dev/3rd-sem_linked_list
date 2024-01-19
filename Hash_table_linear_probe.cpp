#include <iostream>
using namespace std;
#define FREE -1;
// #define DEL -2;
template <class T>
class myHash_table
{
private:
    T data[10];
    int size;

    int hash(int val)
    {
        return val % 10;
    }

public:
    myHash_table(int tableSize = 10)
    {
        size = tableSize;
        // data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = FREE;
        }
    }
    int probe(T key)
    {
        int idx = hash(key);
        int i = 0;
        while (data[idx] != -1)
        {
            idx = (idx + i) % size;
            i++;
        }
        return (idx) % size;
    }

    void insert(T key)
    {
        int idx = hash(key);
        if (data[idx] != -1)
        {
            idx = probe(key);
        }

        data[idx] = key;
    }
    bool find(T key)
    {
        int idx = hash(key);
        if (data[idx] != key)
        {
            idx = probe(key);
        }
        else
        {
            if (data[idx] == key)
                return true;
            else
                return false;
        }
    }
    void display()
    {

        for (int i = 0; i < size; i++)
        {
            std::cout << " data " << i << " is : " << data[i] << "\n";
        }

        std::cout << "-------------------------------\n";
    }
};

int main()
{
    myHash_table<int> obj_1;
    obj_1.insert(32);
    obj_1.insert(14);
    obj_1.insert(24);
    obj_1.insert(22);
    obj_1.insert(23);
    obj_1.insert(9);
    obj_1.insert(28);
    obj_1.insert(19);
    obj_1.display();
    bool op = obj_1.find(19);
    if (op == 1)
    {
        std::cout << "  Data Fount successfully\n";
    }
    else
    {
        std::cout << "Data not found\n";
    }
    std::cout << "-------------------------------\n";   
    return 0;
}
