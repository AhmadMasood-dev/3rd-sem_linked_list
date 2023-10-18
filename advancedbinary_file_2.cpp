#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class student
{
public:
    int rollnumber;
    char name[20];

    
};
void data(student s[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter a rollnumber of student " << i + 1 << std::endl;
            std::cout << "Roll number is :";
            std::cin >> s[i].rollnumber;
            std::cout << "Name is : ";
            std::cin >> s[i].name;
        }
    }

    void display(student s[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Student is :" << i + 1 << std::endl;
            std::cout << "Roll number is :";
            std::cout << s[i].rollnumber << std::endl;
            std::cout << "Name is : ";
            std::cout << s[i].name << std::endl;
        }
    }
int main()
{
    int size;
    std::cout << "Enter number of students\n";
    std::cin >> size;
    student *std1 = new student[size];
    //  student std1[20];
    data(std1, size);

    display(std1, size);

    cout << "------------------------[]" << endl;
    ofstream file("zain.bin", ios::binary);
    if (!file.is_open())
    {
        cout << "not open";
    }
    else
    {

        file.write((char *)&std1, sizeof(student) * size);
        file.close();
    }
    ifstream filt("zain.bin", ios::binary);
    student *std = new student[size];
    // student std[20];

    filt.read((char *)&std, sizeof(student) * size);

    filt.close();
    display(std, size);
}