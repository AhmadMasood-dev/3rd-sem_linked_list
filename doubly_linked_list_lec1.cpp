#include <iostream>
using namespace std;
template <class T>
struct Node
{
    struct Node<T> *next;
    struct Node<T> *back;
    T data;
};
template <class T>
class doubly_linked_list
{
private:
    Node<T> *front;

public:
    doubly_linked_list()
    {
        front = NULL;
    }
};

int main()
{
    doubly_linked_list<int> obj_1;
    return 0;
}