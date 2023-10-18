#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct student
{
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
int main(int argc, char *argv[])
{
    int size;
    std::cout << "Enter number of students\n";
    std::cin >> size;
    student *std1 = new student[size];
    data(std1, size);
    student *std2 = new student[size];
    if (argc == 2)
    {

        ofstream file1(argv[1], ios::binary | ios::out);
        if (!file1.is_open())
        {
            cout << "File cannot open yet" << endl;
        }
        else
        {
            cout << "file open" << endl;
            file1.write(reinterpret_cast<char *>(&std1), sizeof(student) * size);
            file1.close();
        }
        ifstream file(argv[1], ios::binary | ios::in);
        if (!file.is_open())
        {
            cout << "File cannot open yet" << endl;
        }
        else
        {
            cout << "file open" << endl;
            for (int i = 0; i < size; i++)
            {

                file.read((char *)&std2[i], sizeof(student));
            }

            file.close();
        }
    }

    display(std2, size);
}