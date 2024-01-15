#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class myHash_table
{
private:
    T *data;
    Node<T> *head int hash(int val)
    {
        return val % 10;
    }

public:
    myHash_table(int size = 100)
    {
        data = new T[size];
    }

    void insert(int val)
    {
        int idx = hash(val);
        sorted_insert(T[idx], val);
    }
};

int main()
{
    myHash_table<Node<int>> obj_1;
    cout << "zain";
    return 0;
}