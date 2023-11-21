#include <iostream>
using namespace std;
template <class T>
class queue_hospital
{
private:
    T *array;
    int Front_data, Back_data;
    int size;

public:
    queue_hospital()
    {
        Front_data = 0;
        Back_data = 0;
        size = 10;
        array = new T[size];
    }
    ~queue_hospital()
    {
    }
    bool isFull()
    {
        {
            return (Back_data + 1) % size == Front_data;
        }
    }
    void push(T val)
    {
        if ((Back_data + 1) % size == Front_data)
        {
            throw("This Queue is full");
        }
        else
        {
            Back_data = (Back_data + 1) % size;
            array[Back_data] = val;
        }
    }
    T pop()
    {
        T x;
        if (Front_data == Back_data)
        {
            throw("Queue is empty");
        }
        else
        {
            Front_data = (Front_data + 1) % size;

            x = array[Front_data];
        }
        return x;
    }

    void display()
    {
        int i = Front_data + 1;
        do
        {
            cout << "\ni is : " << array[i];
            i = (i + 1) % size;
        } while (i != (Back_data + 1) % size);

        cout << endl;
    }
};
int main()
{
    try
    {

        queue_hospital<string> obj_1;
        obj_1.push("zain");
        obj_1.push("aa");
        obj_1.push("sas");
        obj_1.isFull();
        obj_1.display();
    }
    catch (const string *e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}