#include <iostream>
#include <vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Vector " << i + 1 << " is : " << v[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Vector " << i + 1 << " is : " << v.at(i) << endl;
    }
}
template <class T>
void print(vector<T> &v)
{
    cout << "prnt function" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Vector " << i + 1 << " is : " << v[i] << endl;
        //  cout << "Vector at " << i + 1 << " is : " << v.at(i) << endl;
    }
    cout << endl;
}
int main()
{
    // vector<int> vec1;
    // vector<char> vec2;
    // cout << "enter size of vector is : ";
    // int size;
    // int element;
    // float op;
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter values in vector " << i + 1 << " is : ";
    //     cin >> element;
    //     vec1.push_back(element);
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter second values in vector " << i + 1 << " is : ";
    //     cin >> op;
    //     vec2.push_back(element);
    // }
    // vec1.pop_back();
    // vector<int>::iterator iter = vec1.begin();
    // vec1.insert(iter + 5, 3, 566);
    // display(vec1);
    // cout << endl;
    // display(vec2);

    vector<int> vt1; // zero length integer vector
    // print(vt1);
    vector<char> vt2(4); // 4-element character vector
    vt2.push_back('a');
    print(vt2);
    cout << vt2.size();
    vector<char> vt3(vt2); // 4-element character form vt2 vector
    print(vt3);
    vector<int> vt4(6, 3); // 6-element vector 3s     // (size,number to store);
    print(vt4);

    return 0;
}