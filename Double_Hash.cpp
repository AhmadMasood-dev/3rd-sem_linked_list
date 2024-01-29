#include <iostream>
using namespace std;
#define FREE -1;
// #define DEL -2;
template <class T>
class myHash_table
{
private:
    T *data;
    int size;

    int hash(int val)
    {
        return (val % 10);
    }

public:
    myHash_table(int tableSize = 10)
    {
        size = tableSize;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = FREE;
        }
    }
    int hash_double(T key)
    {
        int idx = 7 - (key % 7);
        return idx;
    }
    int probe(T key)
    {
        int idx = hash(key);
        int i = 0;
        while (data[idx] != -1 && data[idx] != -2)
        {
            idx = (idx + i * hash_double(key)) % size;
            i++;
        }
        return idx;
    }
    int probe_find(T key)
    {
        int idx = hash(key);
        int i = 0;
        while (data[idx] != key)
        {
            idx = (idx + i * hash_double(key)) % size;
            i++;
            if (i > size)
            {
                throw("Hash table value not found \n");
            }
        }
        return idx;
    }
    void insert(T key)
    {
        if (!full())
        {
            int idx = hash(key);

            if (data[idx] != -1)
            {
                idx = probe(key);
            }

            data[idx] = key;
            //  std::cout<<"idx is : "<<idx<<"data[idx]"<<data[idx]<<"\n";
        }
        else
        {
            display();
            throw("Hash table is full\n");
        }
    }
    bool find(T key)
    {
        if (!empty())
        {
            int idx = hash(key);
            if (data[idx] != key)
            {
                idx = probe_find(key);
            }

            if (data[idx] == key)
                return true;
            else
                return false;
        }
        else
        {
            throw("Hash table is empty\n");
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
    void delete_key(T key)
    {
        if (!empty())
        {
            int idx = hash(key);

            if (data[idx] != key)
            {
                idx = probe_find(key);
            }

            if (data[idx] == key)
                data[idx] = -2;
            else
                return;
        }
        else
        {

            throw("Hash table is empty\n");
        }
    }
    bool full()
    {

        int i = 0;

        while ((data[i] != -1 && data[i] != -2) && i <= size)
        {
            i++;
        }
        if (i - 1 == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool empty()
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] != -1 && data[i] != -2)
            {
                return false;
            }
        }
        return true; // The table is empty
    }
};

int main()
{
    try
    {

        myHash_table<int> obj_1;
        obj_1.insert(5);
        obj_1.insert(25);
        obj_1.insert(15);
        obj_1.insert(35);
        obj_1.insert(95);

        obj_1.display();
        bool op = obj_1.find(35);
        if (op == 1)
        {
            std::cout << "  Data Found successfully\n";
        }
        else
        {
            std::cout << "Data not found\n";
        }
        std::cout << "-------------------------------\n";
        obj_1.delete_key(35);

        obj_1.display();

        std::cout << "-------------------------------\n";
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    return 0;
}
