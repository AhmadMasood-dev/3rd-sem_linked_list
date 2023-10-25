#include <iostream>
using namespace std;
template <class T, class T2>
class vector
{
private:
    T array1;
    T2 array2;

public:
    vector(T a, T2 b)
    {
        array1 = a;
        array2 = b;
    }
    void display()
    {
        cout << array1 << endl
             << array2;
    }
};

int main()
{
    vector<int, char> v1(3, 'a');
    v1.display();

    return 0;
}