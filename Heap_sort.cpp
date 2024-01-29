#include <iostream>

void reheapdown(int data[], int first, int last)
{
    int left, right, max;
    left = (first * 2) + 1;
    right = left + 1;
    max = left;
    if (left <= last)
    {
        if (right <= last && data[right] > data[left])
        {
            max = right;
        }
        if (data[first] < data[max])
        {
            int temp = data[max];
            data[max] = data[first];
            data[first] = temp;
            reheapdown(data, max, last);
        }
    }
}

void display(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << data[i] << "\t";
    }
    std::cout << "--------------------\n";
}
void sort(int data[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        reheapdown(data, i, n - 1);
    }
    display(data, n);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        reheapdown(data, 0, i - 1);
    }
}

int main()
{

    int array[] = {2, 7, 4, 6, 88, 56, 75, 23, 55};
    int n = 9;

    display(array, n);
    sort(array, n);
    display(array, n);
    return 0;
}
