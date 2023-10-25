#include <iostream>
using namespace std;
template <class T>
class vector
{
private:
    T *array;
    int size;

public:
    vector(int m)
    {
        size = m;
        array = new T[size];
    }
    
    T vectorsum(vector &v)
    {
        T d = 0;
        for (int i = 0; i < size; i++)
        {

            d += array[i] * v.array[i];
        }
        return d;
    }
    void setvalues(){
        for (int i = 0; i < size; i++)
        {
            array[i]=1.1;
        }
        
    }
};

int main()
{
    vector <float>v1(3);
    v1.setvalues();
    vector <float>v2(3);
    v2.setvalues();
    float x=v1.vectorsum(v2);
    cout<<"value is : "<<x<<endl;

    return 0;
}