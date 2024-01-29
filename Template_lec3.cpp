#include <iostream>
using namespace std;

// class vector
// {
// private:
//     T1 array1;
//     T2 array2;

// public:
//     vector(T1 a, T2 b)
//     {
//         array1 = a;
//         array2 = b;
//     }
// }; 
template <class T1, class T2>
float avg(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;

    return avg;
}
template <class T>
void swapp(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    // vector<> v1(3.7, 6.8);
    float h;
    h = avg(4.5, 6.6);
    cout << "h is : " << h << endl;
    int x = 7, y = 9;
    swapp(x, y);
    cout << "X is and Y is : " << x << "  " << y << endl;
    return 0;
}